/*
Parameters:
	
src_seq: Sequence of an array of points.

header_size: Header size of the approximated curve[s]

storage: Container for the approximated contours. If it is NULL, 
         the input sequences’ storage is used

method: Approximation method; only CV_POLY_APPROX_DP is supported, 
        that corresponds to the Douglas-Peucker algorithm

parameter: Method-specific parameter; in the case of CV_POLY_APPROX_DP 
           it is a desired approximation accuracy

parameter2: If case if src_seq is a sequence, the parameter determines 
            whether the single sequence should be approximated or all 
            sequences on the same level or below src_seq (see FindContours
            for description of hierarchical contour structures). If src_seq 
            is an array CvMat* of points, the parameter specifies whether the
            curve is closed ( parameter2 !=0) or not ( parameter2 =0)
*/

CvSeq* cvApproxPoly(const void* src_seq, int header_size,
CvMemStorage* storage, int method, double eps, int recursive=0 )
