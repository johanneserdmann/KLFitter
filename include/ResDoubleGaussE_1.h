/*!
 * \class KLFitter::ResDoubleGaussE_1
 * \brief A class describing a resolution parameterized with a double Gaussian. 
 * \author Kevin Kr&ouml;ninger
 * \version 1.3
 * \date 03.12.2009
 *
 * This class offers a simple parameterization of a resolution. The
 * parameterization is a double Gaussian with energy dependent
 * parameters.
 */

// --------------------------------------------------------- 

#ifndef RESDOUBLEGAUSSE_1
#define RESDOUBLEGAUSSE_1

#include <vector>
#include "ResolutionBase.h" 
#include <iostream>

// --------------------------------------------------------- 

/*!
 * \namespace KLFitter
 * \brief The KLFitter namespace
 */
namespace KLFitter
{

  class ResDoubleGaussE_1 : public ResolutionBase
  {
                
  public: 
                
    /** \name Constructors and destructors */ 
    /* @{ */ 
                
    /** 
     * The default constructor. 
     */ 
    ResDoubleGaussE_1(const char * filename); 

    /**
     * A constructor.
     * @param parameters The parameters of the parameterization. 
     */
    ResDoubleGaussE_1(std::vector<double> const& parameters);

    /**
     * The default destructor.
     */
    virtual ~ResDoubleGaussE_1(); 

    /* @} */
    /** \name Member functions (Get)  */
    /* @{ */

    /**
     * Return the probability of the true value of x given the
     * measured value, xmeas.
     * @param x The true value of x.
     * @param xmeas The measured value of x.
     * @return The probability. 
     */ 
    double p(double x, double xmeas); 

    /* @} */
    /** \name Member functions (Set)  */
    /* @{ */
        
    /* @} */
    /** \name Member functions (misc)  */
    /* @{ */
                
    /* @} */

    /**
     * Sanity check for double gaussian parameters p2, p3 and p5 (1st sigma, scale and 2nd sigma).
     * @param p2 (the 1st sigma).
     * @param p3 (the scale parameter).
     * @param p5 (the 2nd sigma).
     */
    inline static const void CheckDoubleGaussianSanity(double p2, double &p3, double &p5) {
      if (p2 < 0.) std::cout << "KLFitter::ResDoubleGauss::CheckDoubleGaussianSanity() ERROR IN TRANSFERFUNCTIONS the sigma of the main Gaussian is < 0  -  FIT RESULT WILL NOT BE RELIABLE" << std::endl;
      if (p3 < 0.) p3 = 0.;
      if (p5 < 0.) p3 = 0.;
    }

  private: 

  }; 
        
} // namespace KLFitter 

// --------------------------------------------------------- 

#endif 

