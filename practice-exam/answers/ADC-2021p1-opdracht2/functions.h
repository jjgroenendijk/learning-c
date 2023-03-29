#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define EPSILON 0.0002

typedef struct data {
   int n;
   double d;
} code_t;

/*!
 * \brief compareDoubles
 * \param d1      first double to compare
 * \param d2      second double to compare
 * \param epsilon ????
 * \return positive int if d1 > d2, negative int if d1 < d2, 0 if d1 == d2
 */
int compareDoubles(const double d1, const double d2, const double epsilon);
/*!
 * \brief compareIntegers
 * \param n1      first integer to compare
 * \param n2      second integer to compare
 * \return positive int if n1 > n2, negative int if n1 < n2, 0 if n1 == n2
 */
int compareIntegers(const int n1, const int n2);
/*!
 * \brief compareCodes
 * \param pC1     first struct to compare
 * \param pC2     second struct to compare
 * \return positive int if pC1 > pC2, negative int if pC1 < pC2, 0 if pC1 == pC2
 * \remark compare is first on struct.n then on struct.d
 */
int compareCodes(const void *pC1, const void *pC2);

#endif
