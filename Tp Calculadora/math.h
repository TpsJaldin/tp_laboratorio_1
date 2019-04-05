
#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED

/** \brief this function grabs numbers
 *
 * \param pNumber float*
 * \return void
 *
 */
void enterNumber(float* pNumber);


/** \brief this function adds values
 *
 * \param numA float
 * \param numB float
 * \return float
 *
 */
float addition (float numA,float numB);


/** \brief this function subtract values
 *
 * \param numA float
 * \param numB float
 * \return float
 *
 */
float subtract (float numA,float numB);

/** \brief
 *
 * \param numA float
 * \param numB float
 * \return float
 *
 */
float multiplication (float numA, float numB);


/** \brief this function divide values
 *
 * \param  numA float
 * \param   numB float
 * \return float
 *
 */
float division (float numA, float numB);


/** \brief calculate factorial A
 *
 * \param numA int
 * \param
 * \return int
 *
 */
int factorialA (int numA);


/** \brief calculate factorial B
 *
 * \param numB int
 * \param
 * \return int
 *
 */
int factorialB (int numB);

/*float factorial (float numA, float numB, float *resultA, float *resultB);
*/
#endif
