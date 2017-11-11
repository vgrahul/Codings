#include<stdio.h>

#define Nb 4
int Nr=0;
int Nk=0;

unsigned char in[16], out[16], state[4][4];
unsigned char RoundKey[240];
unsigned char Key[32];

//Sbox function here

// The round constant word array, Rcon[i], contains the values given by
// x to the power (i-1) being powers of x (x is denoted as {02}) in the field GF(28)
//i starts at 1, not 0).

int Rcon[255] = {

0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a,

0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39,

0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a,

0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8,

0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef,

0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc,

0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b,

0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3,

0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94,

0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20,

0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35,

0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f,

0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04,

0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63,

0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd,

0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb };

// This function produces Nb(Nr+1) round keys. The round keys are used in each round to encrypt the states.

void KeyExpansion()
{
int i,j;
unsigned char temp[4],k;
// The first round key is the key itself.
for(i = 0; i < Nk; i++)
{
RoundKey[i * 4]=Key[i * 4];
RoundKey[i * 4 + 1]=Key[i * 4 + 1];
RoundKey[i * 4 + 2]=Key[i * 4 + 2];
RoundKey[i * 4 + 3]=Key[i * 4 + 3];
}
// All other round keys are found from the previous round keys.
while (i < (Nb * (Nr + 1)))
{
for(j = 0; j < 4; j++)
{
temp[j]=RoundKey[(i - 1) * 4 + j];
}
if (i % Nk == 0)
// This function rotates the 4 bytes in a word to the left once.
// [a0,a1,a2,a3] becomes [a1,a2,a3,a0]
// Function RotWord()
{
k = temp[0];
temp[0] = temp[1];
temp[1] = temp[2];
temp[2] = temp[3];
temp[3] = k;
}
// SubWord() is a function that takes a four-byte input word and
// applies the S-box to each of the four bytes to produce an output word.
// Function Subword()
{
temp[0]=getSBoxValue(temp[0]);
temp[1]=getSBoxValue(temp[1]);
temp[2]=getSBoxValue(temp[2]);
temp[3]=getSBoxValue(temp[3]);
}
temp[0] = temp[0] ^ Rcon[i/Nk];
}

else if (Nk > 6 && i % Nk == 4)
{
// Function Subword()
{
temp[0]=getSBoxValue(temp[0]);
temp[1]=getSBoxValue(temp[1]);
temp[2]=getSBoxValue(temp[2]);
temp[3]=getSBoxValue(temp[3]);
}
}
RoundKey[i * 4 + 0] = RoundKey[(i - Nk) * 4 + 0] ^ temp[0];
RoundKey[i * 4 + 1] = RoundKey[(i - Nk) * 4 + 1] ^ temp[1];
RoundKey[i * 4 + 2] = RoundKey[(i - Nk) * 4 + 2] ^ temp[2];
RoundKey[i * 4 + 3] = RoundKey[(i - Nk) * 4 + 3] ^ temp[3];
i++;
}
}

// This function adds the round key to state.
// The round key is added to the state by an XOR function.
void AddRoundKey(int round)
{
int i,j;
for(i = 0; i < 4; i++)
{
for(j = 0; j < 4; j++)
{
state[j][i] ^= RoundKey[round * Nb * 4 + i * Nb + j];
}
}
}
// The SubBytes Function Substitutes the values in the
// state matrix with values in an S-box.
void SubBytes()
{
int i,j;
for(i = 0; i < 4; i++)
{
for(j = 0; j < 4; j++)
{
state[i][j] = getSBoxValue(state[i][j]);
}
}
}
// The ShiftRows() function shifts the rows in the state to the left.
// Each row is shifted with different offset.
// Offset = Row number. So the first row is not shifted.
void ShiftRows()
{
unsigned char temp;
// Rotate first row 1 columns to left
temp=state[1][0];
state[1][0]=state[1][1];
state[1][1]=state[1][2];
state[1][2]=state[1][3];
state[1][3]=temp;
// Rotate second row 2 columns to left
temp=state[2][0];
state[2][0]=state[2][2];
state[2][2]=temp;
temp=state[2][1];
state[2][1]=state[2][3];
state[2][3]=temp;
// Rotate third row 3 columns to left
temp=state[3][0];
state[3][0]=state[3][3];
state[3][3]=state[3][2];
state[3][2]=state[3][1];
state[3][1]=temp;
}
#define xtime(x) ((x<<1) ^ (((x>>7) & 1) * 0x1b))
// MixColumns function mixes the columns of the state matrix
void MixColumns()
{
int i;
unsigned char Tmp,Tm,t;
for(i = 0; i < 4; i++)
{
t=state[0][i];
Tmp = state[0][i] ^ state[1][i] ^ state[2][i] ^ state[3][i] ;
Tm = state[0][i] ^ state[1][i] ; Tm = xtime(Tm); state[0][i] ^= Tm ^ Tmp ;
Tm = state[1][i] ^ state[2][i] ; Tm = xtime(Tm); state[1][i] ^= Tm ^ Tmp ;
Tm = state[2][i] ^ state[3][i] ; Tm = xtime(Tm); state[2][i] ^= Tm ^ Tmp ;
Tm = state[3][i] ^ t ; Tm = xtime(Tm); state[3][i] ^= Tm ^ Tmp ;
}
}
// Cipher is the main function that encrypts the PlainText.
void Cipher()
{
int i,j,round=0;
//Copy the input PlainText to state array.
for(i = 0; i < 4; i++)
{
for(j = 0; j < 4; j++)
{
state[j][i] = in[i * 4 + j];
}
}
// Add the First round key to the state before starting the rounds.
AddRoundKey(0);
// There will be Nr rounds.
// The first Nr-1 rounds are identical.
// These Nr-1 rounds are executed in the loop below.
for(round = 1;round < Nr; round++)
{
SubBytes();
ShiftRows();
MixColumns();
AddRoundKey(round);
}
// The last round is given below.
// The MixColumns function is not here in the last round.
SubBytes();
ShiftRows();
AddRoundKey(Nr);
// The encryption process is over.
// Copy the state array to output array.
for(i = 0; i < 4; i++)
{
for(j = 0; j < 4; j++)
{
out[i * 4 + j]=state[j][i];
}
}
}
int main()
{
int i;
//Clear the input buffer
flushall();
//Recieve the Key from the user
printf("Enter the Key in hexadecimal: ");
for(i = 0; i < Nk * 4; i++)
{
scanf("%x",&Key[i]);
//break();
}
printf("Enter the PlainText in hexadecimal: ");
for(i = 0; i < Nb * 4; i++)
{
scanf("%x",&in[i]);
//break();
}
// The KeyExpansion routine must be called before encryption.
KeyExpansion();
// The next function call encrypts the PlainText with the Key using AES algorithm.
Cipher();
// Output the encrypted text.
printf("\nText after encryption:\n");
for(i = 0;i < Nk * 4; i++)
{
printf("%02x ",out[i]);
}
printf("\n\n");
return 0;
} 
