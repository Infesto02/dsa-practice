class Recursion{
    
    int FactorialOfN( int n){

        int factorial = 1 ;
        if (n == 0) return 1;
        else factorial = n * FactorialOfN(n-1);
        
        return factorial;
    }
};