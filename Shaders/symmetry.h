// symmetry operations
// all points p(x,y) in range [0,1] center @ (0.5, 0.5), z component is ignored

point mirror_v(point p){
  return point(p[0],1-p[1],p[2]);
}

point mirror_h(point p){
  return point(1-p[0],p[1],p[2]);
}

point mirror_xy(point p){
  return point(p[1],p[0],p[2]);
}

point rotate_180(point p){
  return point(1-p[0], 1-p[1], p[2]);
}

point rotate_90(point p){
  vector v = vector(0.5, 0.5, 0);
  point q = p - v;
  q=point(q[1],-q[0],0);
  return q+v;
}

point rotate_270(point p){
  vector v = vector(0.5, 0.5, 0);
  point q = p - v;
  q=point(-q[1],q[0],0);
  return q+v;
}

point rotate_point_angle(point p, point q, float angle){
  vector z = vector(0, 0, 1);
  return rotate(p, radians(angle), q, q + z);
}

point mirror_line(point p, float a, float b){
  float Mx = abs(b)>1e-7 ? (b*p[1]+p[0]-a*b)/(b*b + 1) : p[0];
  float My = a + b*Mx;
  return point(2*Mx-p[0],2*My-p[1],0);
}
