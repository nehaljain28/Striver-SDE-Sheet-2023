for(int k=0;k<v;k++){
	        for(int i=0;i<v;i++){
	            for(int j=0;j<v;j++){
	                
	                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }


//to detect negative cycle
for(int i=0;i<n;i++){
  if(matrix[i][i]<0)return "contains";
}
