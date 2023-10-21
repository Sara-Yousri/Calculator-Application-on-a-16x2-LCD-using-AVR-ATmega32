#define REGISTRER_SIZE 8
#define SET_BIT(reg,bit)    reg|=(1<<bit)
#define CLR_BIT(reg,bit)    reg&=(~(1<<bit))
#define TOGG_BIT(reg,bit)   reg^=(1<<bit)
#define READ_BIT(reg,bit)   (reg&(1<<bit))>>bit
#define IS_BIT_SET(reg,bit) (reg&(1<<bit))>>bit
#define IS_BIT_CLR(reg,bit)  !((reg&(1<<bit))>>bit)
#define ROR(reg,num)         reg=(reg<<(REGISTER_SIZE-num))|(reg>>(num)) //rotate right
#define ROL(reg,num)         reg= (reg>>(REGISTER_SIZE-num))|(reg<<(num)) //rotate left