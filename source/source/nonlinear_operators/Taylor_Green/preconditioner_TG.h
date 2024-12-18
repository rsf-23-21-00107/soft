#ifndef __PRECONDITIONER_TG_H__
#define __PRECONDITIONER_TG_H__


/**
*   Helper preconditioner class for iterative linear solver
*   It is calling a method defined in nonlinear_operator
*   Also requires linear operator while using iterative Krylov solver
*/


namespace nonlinear_operators
{

template<class vector_operations, class nonlinear_operator, class linear_operator> 
class preconditioner_TG
{
public:
    typedef typename vector_operations::scalar_type  T;
    typedef typename vector_operations::vector_type  T_vec;

    preconditioner_TG(nonlinear_operator*& nonlin_op_):
    nonlin_op(nonlin_op_)
    {

    }

    ~preconditioner_TG()
    {

    }
    
    void set_operator(const linear_operator *op_)const
    {
        lin_op = (linear_operator*)op_;
    }

    void apply(T_vec& x)const
    {
        nonlin_op->preconditioner_jacobian_u(x);
    }

private:
    nonlinear_operator* nonlin_op;
    mutable const linear_operator* lin_op;

    
};


}


#endif