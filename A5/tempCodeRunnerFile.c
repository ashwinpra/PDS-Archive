int n1,n2;
    printf("Number 1 = ");
    scanf("%d",&n1);
    printf("Number 2 = ");
    scanf("%d",&n2);
    
    if(checkDigit(n1,n2)==1 && isZazzy(n1,n2)==1) printf("Zazzy pair");
    else printf("Not a Zazzy pair");