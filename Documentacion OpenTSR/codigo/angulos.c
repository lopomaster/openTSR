
double angulo( CvPoint* pt1, CvPoint* pt2, CvPoint* pt0 )
{
    double dx1 = pt1->x - pt0->x;
    double dy1 = pt1->y - pt0->y;
    double dx2 = pt2->x - pt0->x;
    double dy2 = pt2->y - pt0->y;

    return ((dx1*dx2 + dy1*dy2)/sqrt((dx1*dx1 + dy1*dy1)*
            (dx2*dx2 + dy2*dy2) + 1e-10);
}
