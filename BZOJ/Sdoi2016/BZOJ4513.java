package BZOJ;

import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by ckboss on 9/11/16.
 */
public class BZOJ4513 {

    BigInteger n,m;
    BigInteger K;
    BigInteger MOD;
    BigInteger sum;

    int getBit(BigInteger x) {
        for(int i=80;i>=0;i--) {
            if(x.testBit(i)) {
                return i;
            }
        }
        return 0;
    }

    BigInteger rangeSum(BigInteger a,BigInteger b,BigInteger base) {
        BigInteger from = a.add(base);
        BigInteger to = b.add(base);

        if(K.compareTo(to)>=0) return BigInteger.ZERO;

        if((K.subtract(base)).compareTo(BigInteger.ZERO)>=0) {
            from = K.subtract(base).add(from);
        }

        BigInteger num = to.subtract(from).add(BigInteger.ONE);

        return (from.add(to)).multiply(num).shiftRight(1).subtract(num.multiply(K)).mod(MOD);
    }

    void dfs(BigInteger n,BigInteger m,BigInteger base) {
        if(n.compareTo(BigInteger.ZERO)==0||m.compareTo(BigInteger.ZERO)==0) return ;

        if(n.compareTo(m)<0) {
            BigInteger t = n; n = m; m = t;
        }

        if(m.compareTo(BigInteger.ONE)==0) {
            sum = sum.add(rangeSum(BigInteger.ZERO,n.subtract(BigInteger.ONE),base)).mod(MOD);
            return ;
        }

        if(m.equals(BigInteger.ONE)) {
            sum = sum.add(rangeSum(BigInteger.ZERO,n.subtract(BigInteger.ONE),base)).mod(MOD);
        }

        int N = getBit(n);
        int M = getBit(m);

        BigInteger NSHIFT = BigInteger.ONE.shiftLeft(N);

        if(N==M) {

            sum = sum.add(rangeSum(BigInteger.ZERO,NSHIFT.subtract(BigInteger.ONE),base).multiply(NSHIFT)).mod(MOD);

            sum = sum.add(rangeSum(BigInteger.ZERO,NSHIFT.subtract(BigInteger.ONE),base.add(NSHIFT)).multiply(m.subtract(NSHIFT))).mod(MOD);

            sum = sum.add(rangeSum(BigInteger.ZERO,NSHIFT.subtract(BigInteger.ONE),base.add(NSHIFT)).multiply(n.subtract(NSHIFT))).mod(MOD);

            dfs(n.subtract(NSHIFT),m.subtract(NSHIFT),base);
        }
        else {

            sum = sum.add(rangeSum(BigInteger.ZERO,NSHIFT.subtract(BigInteger.ONE),base).multiply(m)).mod(MOD);

            dfs(n.subtract(NSHIFT),m,base.add(NSHIFT));

        }
    }

    BZOJ4513() {
        Scanner in = new Scanner(System.in);
        int T_T = in.nextInt();
        while(T_T-->0) {

            n = in.nextBigInteger();
            m = in.nextBigInteger();
            K = in.nextBigInteger();
            MOD = in.nextBigInteger();

            sum = BigInteger.ZERO;
            dfs(n,m,BigInteger.ZERO);

            System.out.println(sum.mod(MOD));
        }
    }

    public static void main(String[] args) {
        new BZOJ4513();
    }
}

