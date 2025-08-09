#include <bits/stdc++.h>
#define ll long long
using namespace std;

const double eps=1e-10,PI=acos(-1);

struct Point{
  double x,y;
  Point(double x=0,double y=0):x(x),y(y){}//构造函数,方便代码编写
};

typedef Point Vector;//从程序实现上看,Vector只是Point的别名

Vector operator + (Vector A,Vector B){ return Vector(A.x+B.x,A.y+B.y);}//向量+向量=向量,点+向量=点
Vector operator - (Vector A,Vector B){ return Vector(A.x-B.x,A.y-B.y);}//点-点=向量
Vector operator * (Vector A,double p){ return Vector(A.x*p,A.y*p);}//向量*数=向量
Vector operator / (Vector A,double p){ return Vector(A.x/p,A.y/p);}//向量/数=向量

bool operator < (const Point& a,const Point& b)
{ return a.x<b.x||(a.x==b.x&&a.y<b.y);}

inline int dcmp(double x)
{ if(fabs(x)<eps) return 0; else return x<0?-1:1;}

bool operator == (const Point& a,const Point& b)
{ return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;}
//极角函数: (x,y) --> atan2(y,x)

double Dot(Vector A,Vector B){ return A.x*B.x+A.y*B.y;}//点乘
double Length(Vector A){ return sqrt(Dot(A,A));}//长度
double Angle(Vector A,Vector B){ return acos(Dot(A,B)/Length(A)/Length(B));}//夹角(利用cos(...)=(a·b)/(|a||b|))

double Cross(Vector A,Vector B){ return A.x*B.y-A.y*B.x;}
double Area2(Point A,Point B,Point C){ return Cross(B-A,C-A);}

Vector Rotate(Vector A,double rad)//逆时针旋转
{ return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));}//可用极坐标证明

Vector Normal(Vector A){//确保A不是零向量
  double L=Length(A);
  return Vector (-A.y/L,A.x/L);
}//单位法线(左转90°,长度归一化)

Point GetLineIntersection(Point P,Vector v,Point Q,Vector w){//确保两直线P+tv,Q+tw有唯一交点(Cross(w,v)!=0)
  Vector u=P-Q;
  double t=Cross(w,u)/Cross(v,w);
  return P+v*t;
}//精度要求高,则自定义分数类

double DistanceToLine(Point P,Point A,Point B){
  Vector v1=B-A,v2=P-A;
  return fabs(Cross(v1,v2)/Length(v1));
}//点到直线距离

double DistanceToSegment(Point P,Point A,Point B){
  if(A==B) return Length(P-A);
  Vector v1=B-A,v2=P-A,v3=P-B;
  if(dcmp(Dot(v1,v2))<0) return Length(v2);//用点积来判定P点位置
  if(dcmp(Dot(v1,v3))>0) return Length(v3);//两向量夹角为钝则点乘为负,锐为正
  return fabs(Cross(v1,v2)/Length(v1));
}//点到线段距离

Point GetLineProjection(Point P,Point A,Point B){
  Vector v=B-A;
  return A+v*(Dot(v,P-A)/Dot(v,v));
}//点在直线上的投影

bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2){
  double c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1),
         c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
  return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;//每条线段的两个端点都在另一线段的两侧(叉积符号不同)
}//判断线段是否相交(不算端点)

bool Onsegment(Point p,Point a1,Point a2){
  return dcmp(Cross(a1-p,a2-p))==0&&dcmp(Dot(a1-p,a2-p))<0;
}//判断点是否在线段上(不含端点)

double PolygonArea(Point* p,int n){//无论是凹凸多边形都可如此计算
  double area=0;
  for(int i=1;i<n-1;++i)
    area+=Cross(p[i]-p[0],p[i+1]-p[0]);
  return area/2.0;
}//多边形有向面积

struct Line{
  Point p;
  Vector v;
  Line(Point p={0,0},Vector v={0,0}):p(p),v(v){}
  Point GetPoint(double t){ return p+v*t;}//求点
  Line move(double d){ return Line(p+Normal(v)*d,v);}//平移
};

bool VectorParallel(Vector v,Vector w)
{ return dcmp(Cross(v,w))==0;}//判断两向量是否平行-->叉乘为0

int isPointInPolygon(Point p,const vector<Point>& poly){//判断点是否在多边形内部(转角法)
  int wn=0,n=poly.size();
  for(int i=0;i<n;++i){
    if(Onsegment(p,poly[i],poly[(i+1)%n])) return -1;//在边界上
    int k=dcmp(Cross(poly[(i+1)%n]-poly[i],p-poly[i]));
    int d1=dcmp(poly[i].y-p.y),d2=dcmp(poly[(i+1)%n].y-p.y);//叉积判断点在边的左边还是右边
    if(k>0&&d1<=0&&d2>0) ++wn;
    if(k<0&&d2<=0&&d1>0) --wn;
  } return wn?1:0;//1为内部
} 

int ConvexHull(Point* p,int n,Point* ch){//求凸包,输入点数组p,个数为n,输出点数组ch,输入不能有重复点!
  sort(p,p+n);
  int m=0;
  for(int i=0;i<n;++i){
    while(m>1&&dcmp(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<=0) --m;//如果不允许在边上存在点,可换成<,同下
    ch[m++]=p[i];
  }
  int k=m;
  for(int i=n-2;i>=0;--i){
    while(m>k&&dcmp(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<=0) --m;
    ch[m++]=p[i];
  }
  return n>1?m-1:m;//返回凸包顶点数
}

struct Circle{
  Point c;
  double r;
  Circle(Point c={0,0},double r=0):c(c),r(r){}
  Point GetPoint(double a){ return Point(c.x+cos(a)*r,c.y+sin(a)*r);}//通过圆心角来求圆上点坐标
};

double torad(double rad)//角度转化成弧度
{ return rad/180*PI;}

int GetLineCircleIntersection(Line L,Circle C,double& t1,double& t2,vector<Point>& sol){/*也可用勾股定理求*/
  double a=L.v.x,b=L.p.x-C.c.x,c=L.v.y,d=L.p.y-C.c.y;//(t*v.x+(p.x-c.x))^2+(t*v.y+(p.y-c.y))^2=r^2;
  double e=a*a+c*c,f=2*(a*b+c*d),g=b*b+d*d-C.r*C.r;//即(a^2+c^2)t^2+2(ab+cd)t+(b^2+d^2-r^2)=0;
  double delta=f*f-4*e*g;//判别式
  if(dcmp(delta)<0) return 0;//相离
  if(!dcmp(delta)){
    t1=t2=-f/(2*e); sol.push_back(L.GetPoint(t1));
    return 1;
  }//相切
  t1=(-f-sqrt(delta))/(2*e); sol.push_back(L.GetPoint(t1));
  t2=(-f+sqrt(delta))/(2*e); sol.push_back(L.GetPoint(t2));
  return 2;//相交
}//返回圆与直线交点个数,sol存放交点本身(且不清空sol)

double PolarAngle(Vector v){ return atan2(v.y,v.x);}//向量极角

int GetCircleCircleIntersection(Circle C1,Circle C2,vector<Point>& sol){//求圆与圆交点
  double d=Length(C1.c-C2.c);
  if(dcmp(d)==0){//同圆心
    if(dcmp(C1.r-C2.r)==0) return -1;//两圆重合
    return 0;
  }
  if(dcmp(C1.r+C2.r-d)<0) return 0;//相离
  if(dcmp(fabs(C1.r-C2.r)-d)>0) return 0;//内含
  
  double a=PolarAngle(C2.c-C1.c);//向量C1C2的极角
  double da=acos((C1.r*C1.r+d*d-C2.r*C2.r)/(2*C1.r*d));//余弦定理求C1C2到C1P的角
  Point p1=C1.GetPoint(a-da),p2=C1.GetPoint(a+da);
  sol.push_back(p1);
  if(p1==p2) return 1;//== 已经重载
  return sol.push_back(p2),2;
}

int GetTangents(Point p,Circle C,Vector* v){//过点p到圆C切线:v[i]是第i条切线的向量
  Vector u=C.c-p;
  double dist=Length(u);
  if(dist<C.r) return 0;//点在圆内
  if(!dcmp(dist-C.r)) return v[0]=Normal(u),1;//点在圆上
  double ang=asin(C.r/dist);
  v[0]=Rotate(u,-ang),v[1]=Rotate(u,ang);
  return 2;
}//返回切线个数

int GetCommonTangents(Circle A,Circle B,Point* a,Point* b){//a[i]和b[i]分别是第i条切线在圆A和B上的切点
  int cnt=0;
  if(dcmp(A.r-B.r)<0){ swap(A,B); swap(a,b);}//使A.r>=B.r
  double d2=Length(A.c-B.c);
  double rdiff=A.r-B.r,rsum=A.r+B.r;//r1-r2和r1+r2
  if(dcmp(d2-rdiff)<0) return 0;//1.内含
  
  double base=atan2(B.c.y-A.c.y,B.c.x-A.c.x);
  if(d2==0&&A.r==B.r) return -1;//2.两圆重合
  if(!dcmp(d2-rdiff)){//3.内切,1条切线
    a[cnt]=A.GetPoint(base); b[cnt]=B.GetPoint(base); ++cnt;
    return 1;
  }
  //有外公切线
  double ang=acos(rdiff/d2);
  a[cnt]=A.GetPoint(base+ang); b[cnt]=B.GetPoint(base+ang); ++cnt;
  a[cnt]=A.GetPoint(base-ang); b[cnt]=B.GetPoint(base-ang); ++cnt;
  if(!dcmp(d2-rsum)){//外切
    a[cnt]=A.GetPoint(base); b[cnt]=B.GetPoint(base+PI); ++cnt;
  } else if(d2>rsum){//相离
    double ang=acos((A.r+B.r)/d2);
    a[cnt]=A.GetPoint(base+ang); b[cnt]=B.GetPoint(base+ang+PI); ++cnt;
    a[cnt]=A.GetPoint(base-ang); b[cnt]=B.GetPoint(base-ang+PI); ++cnt;
  } return cnt;
}//返回公切线条数,-1表示无穷条公切线

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  
  return 0;
}