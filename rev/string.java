
public class string
{
    public static boolean isString(char s){
        if((s >= '0' && s <= '9') || (s >= 'a' && s <= 'z')){
            return true;
        }
        return false;
    }
    
    public static boolean palindrome(String str){
        int start = 0;
        int end =str.length() -1;
        while(start < end){
        if(!isString(str.charAt(start))) {
            start++;
            continue;
        }
        if(!isString(str.charAt(end))){
            end--;
            continue;
        }
        
        if(Character.toLowerCase(str.charAt(start)) != Character.toLowerCase(str.charAt(end))){
            return false;
        }start++;end--;
        }
        return true;
    }
    
    public static String occurence(String str, String target){
        while(str.contains(target)){
            int index = str.indexOf(target);
            str = str.substring(0,index) + str.substring(index + target.length());
        }
        return str;
    }
    
    public static boolean isfreSame(int freq[], int winfreq[]){
        for(int i = 0;i<26;i++){
            if(freq[i] != winfreq[i]){
                return false;
            }
        }
        return true;
    }
    
    public static boolean permutation(String str, String s){
        int freq[] = new int[26];
        for(int i =0;i<s.length();i++){
            freq[s.charAt(i) - 'a']++;
        }
        
        int windowsize = s.length();
        for(int i =0;i<str.length();i++){
            int wdindex =0; int index = i;
            int winfreq[] = new int[26];
            
            while(wdindex < windowsize && index <str.length()){
                winfreq[str.charAt(index) - 'a']++;
                wdindex++;
                index++;
            }
            
            if(isfreSame(freq,winfreq)){
                return true;
            }
        }
        return false;
    }
    
    public static String reverseWords1(String str){
        String reversed = "";
        String  words[] = str.split(" ");
        
        for(int i = words.length-1;i>= 0;i--){
            reversed += words[i] + " ";
        }
        
        return reversed;
    }
    
    public static StringBuilder reverseWords2(String str){
        StringBuilder sb = new StringBuilder();
        String words[] = str.split(" ");
        
        for(int i = words.length-1;i>= 0;i--){
            sb.append(words[i]).append(" ");
        }
        
        return sb;
        
    }
    
    public static char[] comperess(char arr[]){
        int n = arr.length;
        int index = 0;
        for(int i = 0;i<n;i++){
            char c = arr[i];
           int  count = 0;
            
            while(i<n && c == arr[i]){
                count++;
                i++;
            }
            
            if(count ==1){
                arr[index] = c;
                index++;
            }else{
                arr[index] = c;
                index++;
                String str = Integer.toString(count);
                for(char dif : str.toCharArray()){
                    arr[index] = dif;
                    index++;
                }
            }
            i--;
        }
        return arr;
    }

	public static void main(String[] args) {
// 		System.out.println("Hello World");
// 	//	String str = "madam";
// 		String str = "abcxyzabc123abc";
//         String target = "abc";

//         String result = occurence(str, target);
//         System.out.println(result); 
// 		System.out.println(palindrome(str));
		char arr[] = {'a','a','b','c','c'};
		System.out.println(reverseWords1("HEllo world"));
		System.out.println(reverseWords2("Hello world"));
		System.out.println(comperess(arr));
	}
}
