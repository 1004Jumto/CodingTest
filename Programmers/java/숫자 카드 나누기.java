import java.util.Arrays;

class Solution {
    public int solution(int[] arrayA, int[] arrayB) {
        // 각 배열의 최대공약수를 구한다
        int gcdA = getArrayGCD(arrayA);
        int gcdB = getArrayGCD(arrayB);
        // System.out.println(gcdA);
        // System.out.println(gcdB);
        
        // 최대공약수에 대한 약수 배열을 생성한다
        int[] divisorA = new int[gcdA];
        int[] divisorB = new int[gcdB];
        
        
        for(int i = 1, idx = 0; i <= Math.sqrt(gcdA); i++){
            if(gcdA % i == 0){
                divisorA[idx++] = i;
                if(gcdA / i != i) divisorA[idx++] = gcdA / i;
            }
        }
        
        
        for(int i = 1, idx = 0; i <= Math.sqrt(gcdB); i++){
            if(gcdB % i == 0){
                divisorB[idx++] = i;
                if(gcdB / i != i) divisorB[idx++] = gcdB / i;
            }
        }
        

        // 약수 배열을 내림차순(혹은 역으로) 순회하며 나눠지는지 검사한다
        Arrays.sort(divisorA);
        Arrays.sort(divisorB);
        
        // System.out.println(Arrays.toString(divisorA));
        // System.out.println(Arrays.toString(divisorB));
        
        int A = 0;
        for(int i = divisorA.length - 1; i >= 0 && divisorA[i] != 0; i--){
            boolean isDivided = false;
            for(int n : arrayB){
                if(n % divisorA[i] == 0) {isDivided = true; break;}
            }
            if(!isDivided) {
                A = divisorA[i];
                break;
            } 
        }
        
        int B = 0;
        for(int i = divisorB.length - 1; i >= 0 && divisorB[i] != 0; i--){
            boolean isDivided = false;
            for(int n : arrayA){
                if(n % divisorB[i] == 0) {isDivided = true; break;} 
            }
            if(!isDivided) {
                B = divisorB[i];
                break;
            } 
        }
        
        System.out.println(A);
        System.out.println(B);
        
        return A < B ? B : A;
        
    }
    
    // 최대공약수 구하는 메소드 -> param int[] return int
    private int getArrayGCD(int[] arr){
        int res = arr[0];
        
        for(int i = 1; i < arr.length; i++){
            res = gcd(res, arr[i]);
        }
        
        return res;
    }
    
    private int gcd(int a, int b){
        while(b != 0){
            int temp = a % b;
            a = b;
            b = temp;
        }
        
        return a;
        
//         if(b == 0) return; 
//         return gcd(b, a % b);
    }
}

/*아래는 각 배열의 약수, 공약수 배열을 생성 
    -> 공약수에서 다른 배열의 약수를 제외한 가장 큰 수를 찾는 로직*/
// import java.util.Arrays;

// class Solution {
//     public int solution(int[] arrayA, int[] arrayB) {
//         int answer = 0;
//         Arrays.sort(arrayA);
//         Arrays.sort(arrayB);
        
//         // 각 배열의 약수, 공약수 배열을 생성
//         // 약수는 1이상, 공약수는 arr.length 이상
//         int[] arrA = new int[arrayA[arrayA.length-1] + 1];
//         int[] arrB = new int[arrayB[arrayB.length-1] + 1];
         
        
//         // 50만번 x 50만번 
//         // 초 당 1억번 기준
//         for(int n : arrayA){
//             for(int i = 1; i <= Math.sqrt(n); i++){
//                 if(n % i == 0) {
//                     arrA[i]++;
//                     if (i != n / i) arrA[n / i]++;
//                 }
//             }
//         }
//         for(int n : arrayB){
//             for(int i = 1; i <= Math.sqrt(n); i++){
//                 if(n % i == 0) {
//                     arrB[i]++; 
//                     if (i != n / i) arrB[n / i]++;
//                 }
//             }
//         }  
        
//         int maxA = 0, maxB = 0;
//         int aLen = arrA.length; 
//         int bLen = arrB.length;
//         int len = aLen < bLen ? aLen : bLen;
        
//         // A의 공약수 중 B의 약수를 제외
//         for(int i = len-1; i >=0; i--){
//             if(arrA[i] == arrayA.length && arrB[i] == 0){
//                 maxA = i; break;
//             }            
//         }
//         if(len < aLen){
//             for(int i = aLen-1; i >=len ; i--){
//                 if(arrA[i] == arrayA.length) {maxA = i; break;}
//             }    
//         }
        
        
//         // B의 공약수 중 A의 약수를 제외
//         for(int i = len-1; i >=0; i--){
//             if(arrB[i] == arrayB.length && arrA[i] == 0){
//                 maxB = i; break;
//             }            
//         }
//         if(len < bLen){
//             for(int i = bLen-1; i >= len ; i--){
//                 if(arrB[i] == arrayB.length) {maxB = i;break;}
//             }    
//         }
//         // System.out.println(maxA);
//         // System.out.println(bLen);
//         // System.out.println(maxB);
        
//         answer = maxA < maxB ? maxB : maxA;
        
//         return answer;
//     }
// }