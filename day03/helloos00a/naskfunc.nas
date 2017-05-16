; naskfunc
; TAB=4

[FORMAT "WCOFF"]                    ;   制作目标文件的格式
[BITS 32]                                         ;     制作32位膜使用的机械语言

;制作目标文件的信息

[FILE   "naskfunc.nas"]                 ;   源文件名信息

        GLOBAL      _io_hlt                 ;   程序中包含的函数名

;   以下是实际函数

[SECTION    .text]                      ;   目标文件中谢了这些之后在写程序

_io_hlt:        ; void io_hlt(void);
        HLT
        RES