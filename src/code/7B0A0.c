#include <ultra64.h>
#include "prevent_bss_reordering2.h"
#include "7B0A0.h"

// .bss
s8 D_80134BF0;
s16 gCutsceneLength;
s16 D_80134BF4;
s16 D_80134BF6_unused;
s16 D_80134BF8;
s16 D_80134BFA;
s16 D_80134BFC;
s16* gCutsceneByteCode;
s16* D_80134C04_unused;
struct CutsceneString* gCutsceneString;
s16 D_80134C0C;
s16 D_80134C0E;
s16 D_80134C10;
s16 D_80134C12;
s16 D_80134C14;
s16 D_80134C16;
s16 D_80134C18;
s16 D_80134C1A;
s16 D_80134C1C;
s16 D_80134C1E;
s16 D_80134C20;
s16 D_80134C22;
s8 D_80134C24;
s8 D_80134C25;
s8 D_80134C26;
s16 D_80134C28[0x18];
s16 D_80134C58[0x18];
s16 D_80134C88[0x18];
s16 D_80134CB8[0x18];
s16 D_80134CE8[0x18];
s16 D_80134D18[0x18];

struct UnkStruct80134D48 D_80134D48[0x18];
struct MegaStruct gMegaStruct; // 80134F28

void func_80088B80(void) {
    s16 sp1E;
    gCutsceneLength = -1;
    D_80134BF8 = -1;
    D_80134BF0 = 0;
    D_80134C26 = 0;
    D_80134C24 = 0;
    D_80134C25 = 0;
    D_80134C22 = 0;
    D_80134C0C = 0;
    D_80134C1E = -1, D_80134C1C = -1, D_80134C1A = -1;
    D_80134C20 = -1;
    func_80088D84();
    for (sp1E = 0; sp1E < 0x18; sp1E++) {
        D_80134D48[sp1E].ObjectID = -1;
        D_80134D48[sp1E].unk4 = 0.0f;
        D_80134D48[sp1E].unk8 = 0.0f;
        D_80134D48[sp1E].unkC = 0;
        D_80134D48[sp1E].unkE = 0;
        D_80134D48[sp1E].unk10 = 0;
        D_80134C28[sp1E] = -1;
        D_80134C58[sp1E] = -1;
        D_80134C88[sp1E] = -1;
        D_80134CB8[sp1E] = -1;
        D_80134CE8[sp1E] = -1;
        D_80134D18[sp1E] = 0;
    }
}

void func_80088D84(void) {
    gMegaStruct.D_80134F28.x = gMegaStruct.D_80134F28.y = gMegaStruct.D_80134F28.z = 0.0f;
    gMegaStruct.D_80134F44.x = gMegaStruct.D_80134F44.y = gMegaStruct.D_80134F44.z = 0.0f;
    gMegaStruct.D_80134F34.x = gMegaStruct.D_80134F34.y = gMegaStruct.D_80134F34.z = gMegaStruct.D_80134F40 = 0.0f;
    gMegaStruct.D_80134F50.x = gMegaStruct.D_80134F50.y = gMegaStruct.D_80134F50.z = 0.0f;
    gMegaStruct.D_80134F68.x = gMegaStruct.D_80134F68.y = gMegaStruct.D_80134F68.z = 0.0f;
    gMegaStruct.D_80134F5C.x = gMegaStruct.D_80134F5C.y = gMegaStruct.D_80134F5C.z = gMegaStruct.D_80134F74 = 0.0f;
    gMegaStruct.D_80134F78.x = gMegaStruct.D_80134F78.y = gMegaStruct.D_80134F78.z = 0.0f;
    gMegaStruct.D_80134F90.x = gMegaStruct.D_80134F90.y = gMegaStruct.D_80134F90.z = 0.0f;
    gMegaStruct.D_80134F84.x = gMegaStruct.D_80134F84.y = gMegaStruct.D_80134F84.z = gMegaStruct.D_80134F9C = 0.0f;
    gMegaStruct.D_80134FA0.unk0 = 1;
    gMegaStruct.D_80134FA0.unk2 = 0;
    gMegaStruct.D_80134FA4.unk0 = gMegaStruct.D_80134FA4.unk2 = 0;
    gMegaStruct.D_80134FA8 = 0;
}

void func_80088EAC(s32 arg0) {
    gCutsceneLength = arg0;
    D_80134C0C = 0;
}

void func_80088ECC(void) {
    s16 exit;

    if (gCutsceneLength == -1) {
        return;
    }
    if ((D_80134C0C == 0) && (D_80134BF8 == -1)) {
        D_80134C0C += 1;
        D_80134C12 = 0;
        D_80134C10 = 0;
        D_80134C0E = 0;
        D_80134C16 = 0;
        D_80134C14 = 0;
        D_80134BF8 = -1, D_80134BF4 = -1;
        gCutsceneByteCode = (s16*) 0x8033A000;
    }
    if (D_80134C14 != 0) {
        D_80134C14 -= 1;
        return;
    }
    exit = 0;
    while (exit == 0) {
        switch (*gCutsceneByteCode) {
            case 0x0:
                gCutsceneLength = -1;
                D_80134C0C = 0;
                exit = 1;
                break;
            case 0x1:
                exit = 1;
                break;
            case 0x2:
                D_80134BF8 = gCutsceneByteCode[1];
                D_80134BFA = gCutsceneByteCode[2];
                D_80134BFC = gCutsceneByteCode[3];
                gCutsceneByteCode += 3;
                break;
            case 0x5:
                D_80134C14 = gCutsceneByteCode[1] - 1;
                gCutsceneByteCode += 1;
                exit = 1;
                break;
            case 0x6:
                func_8008ABC4(gCutsceneByteCode + 1);
                gCutsceneByteCode += 4;
                break;
            case 0x3C:
                func_8008ABF4(gCutsceneByteCode + 1);
                gCutsceneByteCode += 4;
                break;
            case 0x7:
                func_8008AC08(gCutsceneByteCode + 1);
                gCutsceneByteCode += 1;
                break;
            case 0x8:
                gCameraType = 0;
                break;
            case 0x27:
                func_8008BB0C();
                break;
            case 0x25:
                func_8008AD58(gCutsceneByteCode + 1);
                gCutsceneByteCode += 7;
                break;
            case 0x26:
                func_8008AE64(gCutsceneByteCode + 1);
                gCutsceneByteCode += 6;
                break;
            case 0x9:
                gMegaStruct.D_80134F74 = (f32) gCutsceneByteCode[1] / 10.0f;
                gCutsceneByteCode += 1;
                break;
            case 0xA:
                gMegaStruct.D_80134F50.x = (f32) gCutsceneByteCode[1] / 10.0f;
                gCutsceneByteCode += 1;
                break;
            case 0xB:
                gMegaStruct.D_80134F50.y = (f32) gCutsceneByteCode[1] / 10.0f;
                gCutsceneByteCode += 1;
                break;
            case 0xC:
                gMegaStruct.D_80134F50.z = (f32) gCutsceneByteCode[1] / 10.0f;
                gCutsceneByteCode += 1;
                break;
            case 0xD:
                gMegaStruct.D_80134F5C.x = (f32) gCutsceneByteCode[1] / 10.0f;
                gCutsceneByteCode += 1;
                break;
            case 0xE:
                gMegaStruct.D_80134F5C.y = (f32) gCutsceneByteCode[1] / 10.0f;
                gCutsceneByteCode += 1;
                break;
            case 0xF:
                func_8008B5D4(gCutsceneByteCode + 1);
                gCutsceneByteCode += 2;
                break;
            case 0x10:
                func_8008B624(gCutsceneByteCode + 1);
                gCutsceneByteCode += 4;
                break;
            case 0x11:
                func_8008B6E0(gCutsceneByteCode + 1);
                gCutsceneByteCode += 5;
                break;
            case 0x12:
                func_8008BA3C();
                break;
            case 0x13:
                func_8008C61C();
                break;
            case 0x14:
                func_8008C638();
                break;
            case 0x15:
                func_8008C650();
                break;
            case 0x16:
                func_8008C66C();
                break;
            case 0x17:
                func_8008C684(gCutsceneByteCode + 1);
                gCutsceneByteCode += 4;
                break;
            case 0x18:
                func_8008C778(gCutsceneByteCode + 1);
                gCutsceneByteCode += 5;
                break;
            case 0x19:
                func_8008C9B4(gCutsceneByteCode + 1);
                gCutsceneByteCode += 2;
                break;
            case 0x1A:
                func_8008CADC(gCutsceneByteCode + 1);
                gCutsceneByteCode += 2;
                break;
            case 0x1B:
                func_8008CC04(gCutsceneByteCode + 1);
                gCutsceneByteCode += 2;
                break;
            case 0x1F:
                func_8008CD2C(gCutsceneByteCode + 1);
                gCutsceneByteCode += 4;
                break;
            case 0x20:
                func_8008CE8C(gCutsceneByteCode + 1);
                gCutsceneByteCode += 5;
                break;
            case 0x32:
                func_8008D074(gCutsceneByteCode + 1);
                gCutsceneByteCode += 3;
                break;
            case 0x33:
                func_8008D114(gCutsceneByteCode + 1);
                gCutsceneByteCode += 2;
                break;
            case 0x21:
                func_8008D530(gCutsceneByteCode + 1);
                gCutsceneByteCode += 6;
                break;
            case 0x22:
                func_8008DC8C(gCutsceneByteCode + 1);
                gCutsceneByteCode += 3;
                break;
            case 0x23:
                func_8008E328(gCutsceneByteCode + 1);
                gCutsceneByteCode += 2;
                break;
            case 0x34:
                func_8008E3B0(gCutsceneByteCode + 1);
                gCutsceneByteCode += 3;
                break;
            case 0x39:
                func_8008E418(gCutsceneByteCode + 1);
                gCutsceneByteCode += 3;
                break;
            case 0x24:
                func_8008E81C(gCutsceneByteCode + 1);
                gCutsceneByteCode += 3;
                break;
            case 0x28:
                gMegaStruct.D_80134F68.x = (f32) gCutsceneByteCode[1] / 10.0f;
                gCutsceneByteCode += 1;
                break;
            case 0x29:
                gMegaStruct.D_80134F68.y = (f32) gCutsceneByteCode[1] / 10.0f;
                gCutsceneByteCode += 1;
                break;
            case 0x2A:
                gMegaStruct.D_80134F68.z = (f32) gCutsceneByteCode[1] / 10.0f;
                gCutsceneByteCode += 1;
                break;
            case 0x2B:
                func_8008BC04(gCutsceneByteCode + 1);
                gCutsceneByteCode += 4;
                break;
            case 0x2C:
                func_8008E8A4(gCutsceneByteCode + 1);
                gCutsceneByteCode += 2;
                break;
            case 0x2D:
                func_8008E918(gCutsceneByteCode + 1);
                gCutsceneByteCode += 3;
                break;
            case 0x2E:
                func_8008EAE4(gCutsceneByteCode + 1);
                gCutsceneByteCode += 1;
                break;
            case 0x2F:
                func_8008EB10(gCutsceneByteCode + 1);
                gCutsceneByteCode += 1;
                break;
            case 0x30:
                func_8008EB40(gCutsceneByteCode + 1);
                gCutsceneByteCode += 1;
                break;
            case 0x31:
                func_8008EB6C(gCutsceneByteCode + 1);
                gCutsceneByteCode += 1;
                break;
            case 0x36:
                func_8008EB9C(gCutsceneByteCode + 1);
                gCutsceneByteCode += 1;
                break;
            case 0x35:
                func_8008EBEC(gCutsceneByteCode + 1);
                gCutsceneByteCode += 1;
                break;
            case 0x37:
                func_8008EC3C(gCutsceneByteCode + 1);
                gCutsceneByteCode += 1;
                break;
            case 0x38:
                func_8008ECD0(gCutsceneByteCode + 1);
                gCutsceneByteCode += 1;
                break;
            case 0x3A:
                func_8008ED64(gCutsceneByteCode + 1);
                gCutsceneByteCode += 2;
                break;
            case 0x3B:
                ByteParser_SetObjectScale(gCutsceneByteCode + 1);
                gCutsceneByteCode += 4;
                break;
            case 0x3D:
                func_8008F078(gCutsceneByteCode + 1);
                gCutsceneByteCode += 5;
                break;
            case 0x3E:
                func_8008F3D4(gCutsceneByteCode + 1);
                gCutsceneByteCode += 1;
                break;
            case 0x3F:
                func_8008F63C(gCutsceneByteCode + 1);
                gCutsceneByteCode += 5;
                break;
            case 0x4C:
                func_8008F6AC(gCutsceneByteCode + 1);
                gCutsceneByteCode += 2;
                break;
            case 0x40:
                D_80134C22 = 1;
                break;
            case 0x41:
                D_80134C22 = 0;
                break;
            case 0x42:
                D_80134C24 = 1;
                D_80134C25 = 0;
                break;
            case 0x44:
                D_80134C24 = 2;
                D_80134C25 = 0;
                break;
            case 0x43:
            case 0x45:
                D_80134C24 = 0;
                break;
            case 0x46:
                func_8001FB3C(gCutsceneByteCode[1], gCutsceneByteCode[2], gCutsceneByteCode[3]);
                gCutsceneByteCode += 3;
                break;
            case 0x47:
                D_80134C26 = 1;
                break;
            case 0x48:
                D_80134C26 = 0;
                break;
            case 0x49:
                func_8008884C(1);
                break;
            case 0x4A:
                func_8008884C(0);
                break;
            case 0x4B:
                D_80134BF0 = (s8) gCutsceneByteCode[1];
                gCutsceneByteCode += 1;
                break;
            default:
                exit = 1;
                break;
        }
        gCutsceneByteCode += 1;
    }
}

void func_80089C18(void) {
    if (D_80134BF8 == -1) {
        return;
    }
    if (D_80134C0E == 0) {
        D_80134C0E += 1;
        gCutsceneString = D_80110D4C[D_80134BF8];
        D_80134C16 = D_80110B78[D_80134BF8];
        D_80134C18 = 0xA;
    }
    if (D_80134C16 == 0) {
        if (D_80134C18 == 0) {
            D_80134BF8 = -1;
            D_80134BF0 = 0;
            D_80134C0E = 0;
        } else {
            D_80134C18 -= 1;
        }
    } else {
        D_80134C16 -= 1;
    }
}

/**
 * Print a number with leading zeros per the specified length.
 */
void Cutscene_PrintWithLeadingZeros(s32 value, s32 x, s32 y, s32 len) {
    s32 c;
    s32 digit;
    s32 i;

    for (i = 0; i < len; i++) {
        digit = value % 10; // grab the current digit.

        // if that is 0, we are printing 0 to pad the number.
        if (value == 0) {
            c = 0;
        } else {
            c = digit;
        }

        value /= 10; // reduce the value to the next digit.
        c++;
        Cutscene_RenderChar(x, y, (c % 32) * 8, (c / 32) * 0x10, 0x1A); // print the digit.
        x -= 8;
    }
}

/**
 * Handle the cutscene special prints for printing the timer and score in a text message
 * (Slider Race ending cutscene and Gold Bomber final score).
 */
void Cutscene_HandleSpecialPrints(void) {
    s16 c; // the special character to print
    s32 min;
    s32 sec;
    s32 ms;

    if (D_80134BF0 == 1) {
        // Timer for Slider Race finishing dialogue "Your time is XX:YY:ZZ!"
        c = CHAR_COLON;
        // first calculate the minutes/seconds/ms from the timer score variable.
        Score_UpdateTimer(&min, &sec, &ms);
        // then print the timer
        Cutscene_PrintWithLeadingZeros(min, 192, 184, 2);
        Cutscene_RenderChar(200, 184, (c % 32) * 8, (c / 32) * 16, 26);
        Cutscene_PrintWithLeadingZeros(sec, 216, 184, 2);
        Cutscene_RenderChar(224, 184, (c % 32) * 8, (c / 32) * 16, 26);
        Cutscene_PrintWithLeadingZeros(ms, 240, 184, 2);
        c = CHAR_EXCLAMATION;
        // now print the ! after it
        Cutscene_RenderChar(248, 184, (c % 32) * 8, (c / 32) * 16, 26);
    } else if (D_80134BF0 == 2) {
        // Timer for Gold Bomber final score "Final Score: 00000"
        Cutscene_PrintWithLeadingZeros(D_80177600 * 10, 180, 200, 5);
    }
}

/**
 * Renders the loaded string for the Cutscene.
 */
void Cutscene_HandlePrintText(void) {
    s16 idx;
    s16 yIdx;
    s16 exit;
    s16 count;
    s16 xIdx;
    s16 c;
    s16 id;
    s16 x;
    s16 y;

    if (D_80134BF8 == -1) {
        return;
    }

    Cutscene_RenderTextBG();
    Cutscene_SetupTextPal();
    func_8008A824(gCutsceneString->unk0, gCutsceneString->unk2, gCutsceneString->unk4);

    xIdx = 0;
    count = 0;
    exit = 0;
    yIdx = 0;
    idx = 0;

    while (!exit) {
        if (gCutsceneString->str[idx] == -1) {
            if (gCutsceneString->len == (count + 1)) {
                exit = 1;
            } else {
                count += 1;
                idx += 1;
                yIdx += 1;
                xIdx = 0;
            }
        } else {
            c = gCutsceneString->str[idx];
            id = 0x1A;

            switch (D_80134BFA) {
                case 0:
                    x = ((0x140 - (gCutsceneString->unk6 * 8)) / 2) + (xIdx * 8);
                    break;
                case 1:
                    x = xIdx * 8;
                    break;
                case 2:
                    x = ((xIdx * 8) - (gCutsceneString->unk6 * 8)) + 0x140;
                    break;
                default:
                    x = ((0x140 - (gCutsceneString->unk6 * 8)) / 2) + (xIdx * 8);
                    break;
            }

            switch (D_80134BFC) {
                case 0:
                    y = ((0xF0 - (gCutsceneString->len * 16)) / 2) + (yIdx * 16);
                    break;
                case 3:
                    y = yIdx * 16;
                    break;
                case 4:
                    y = (yIdx * 16) + 0xB8;
                    break;
                default:
                    y = (yIdx * 16) + 0xB8;
                    break;
            }

            Cutscene_RenderChar(x, y, (c % 32) * 8, (c / 32) * 16, id);
            idx++;  // index to the next string character.
            xIdx++; // move the character to the next x coordinate.
        }
    }

    Cutscene_HandleSpecialPrints();
}

void Cutscene_SetupTextPal(void) {
    gDPPipeSync(gMasterDisplayList++);
    gSPClearGeometryMode(gMasterDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                                                   G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gMasterDisplayList++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH);
    gDPSetTexturePersp(gMasterDisplayList++, G_TP_NONE);
    gDPSetRenderMode(gMasterDisplayList++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);
    gDPSetCombineMode(gMasterDisplayList++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetColorDither(gMasterDisplayList++, G_CD_BAYER);
    gDPSetTextureFilter(gMasterDisplayList++, G_TF_BILERP);
    gDPSetTextureLUT(gMasterDisplayList++, G_TT_RGBA16);
    gDPLoadTLUT_pal16(gMasterDisplayList++, 0, gFileArray[26].ptr + 0x10);
}

void Cutscene_RenderTextBG(void) {
    gDPPipeSync(gMasterDisplayList++);
    gSPClearGeometryMode(gMasterDisplayList++, G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                                                   G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gMasterDisplayList++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    gDPSetCombineMode(gMasterDisplayList++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode(gMasterDisplayList++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    gDPSetPrimColor(gMasterDisplayList++, 0, 0, 0x00, 0x00, 0x00, 0x50);
    gDPFillRectangle(gMasterDisplayList++, 24, 180, 298, 220);
}

// combines 3 5-bit masks into a single 32-bit value. Could convert an rgb value?
// The address this is written to does not appear to be used for anything.
void func_8008A824(s16 arg0, s16 arg1, s16 arg2) {
    D_8010CD80[1] = ((arg0 << 11) + (arg1 << 6) + (arg2 * 2) + 1);
}

/**
 * Render the next character in the Cutscene text being rendered using a given character
 * ([s, t] specify the coordinates in tilemap space for the character to use). Also
 * manually specifies the file ID, but its never any value other than 0x1A in practice.
 */
void Cutscene_RenderChar(s16 x, s16 y, s16 s, s16 t, s16 id) {
    gDPLoadMultiTile_4b(gMasterDisplayList++, gFileArray[id].ptr + 0x30, 0, 0, G_IM_FMT_CI, 256, 256, s, t, (s + 8),
                        (t + 16), 0, 0, 0, 0, 0, 0, 0);
    gDPSetTileSize(gMasterDisplayList++, 0, 0, 0, 0x40, 0x40);
    gSPTextureRectangle(gMasterDisplayList++, (x << 2), (y << 2), ((x + 8) << 2), ((y + 16) << 2), 0, 0, 0, 0x400,
                        0x400);
}

void func_8008ABC4(s16* arg0) {
    func_80069E00(0, 0);
}

void func_8008ABF4(s16* arg0) {
}

void func_8008AC08(s16* arg0) {

    switch (*arg0) {
        case 1:
            D_8016E134 = 0;
            gMegaStruct.D_80134FA4.unk0 = 0;
            break;
        case 2:
            D_8016E134 = 1;
            gMegaStruct.D_80134FA4.unk0 = 1;
            func_8008B030();
            break;
        case 3:
            D_8016E134 = 0;
            gMegaStruct.D_80134FA4.unk0 = 1;
            break;
        case 4:
            D_8016E134 = 1;
            gMegaStruct.D_80134FA4.unk0 = 0;
            func_8008B030();
            break;
        default:
            D_8016E134 = 0;
            gMegaStruct.D_80134FA4.unk0 = 0;
            break;
    }

    func_80019B7C();
    if (D_8016E134 == 1) {
        gMegaStruct.D_80134F44.x = gView.eye.x;
        gMegaStruct.D_80134F44.y = gView.eye.y;
        gMegaStruct.D_80134F44.z = gView.eye.z;
    }
}

void func_8008AD58(s16* arg0) {
    gMegaStruct.D_80134F28.x = (f32) arg0[0];
    gMegaStruct.D_80134F28.y = (f32) arg0[1];
    gMegaStruct.D_80134F28.z = (f32) arg0[2];
    gMegaStruct.D_80134F34.x = (f32) arg0[3];
    gMegaStruct.D_80134F34.y = (f32) arg0[4];
    gMegaStruct.D_80134F34.z = (f32) arg0[5];
    gMegaStruct.D_80134F40 = (f32) arg0[6];
    gMegaStruct.D_80134F50.x = 0.0f;
    gMegaStruct.D_80134F50.y = 0.0f;
    gMegaStruct.D_80134F50.z = 0.0f;
    gMegaStruct.D_80134F5C.x = 0.0f;
    gMegaStruct.D_80134F5C.y = 0.0f;
    gMegaStruct.D_80134F5C.z = 0.0f;
    gMegaStruct.D_80134F74 = 0.0f;
}

void func_8008AE64(s16* arg0) {
    s32 sp4;

    sp4 = D_80134D48[arg0[0]].ObjectID;
    gMegaStruct.D_80134F28.x = gObjects[sp4].Pos.x;
    gMegaStruct.D_80134F28.y = gObjects[sp4].Pos.y + arg0[1];
    gMegaStruct.D_80134F28.z = gObjects[sp4].Pos.z;
    gMegaStruct.D_80134F34.x = arg0[2];
    gMegaStruct.D_80134F34.y = arg0[3];
    gMegaStruct.D_80134F34.z = arg0[4];
    gMegaStruct.D_80134F40 = arg0[5];
    gMegaStruct.D_80134FA4.unk2 = (s16) (s32) (f32) arg0[1]; // what the fuck
    gMegaStruct.D_80134FA8 = arg0[0];
    gMegaStruct.D_80134F50.x = 0.0f;
    gMegaStruct.D_80134F50.y = 0.0f;
    gMegaStruct.D_80134F50.z = 0.0f;
    gMegaStruct.D_80134F5C.x = 0.0f;
    gMegaStruct.D_80134F5C.y = 0.0f;
    gMegaStruct.D_80134F5C.z = 0.0f;
    gMegaStruct.D_80134F74 = 0.0f;
}

void func_8008B030(void) {
    gView.at.x = gMegaStruct.D_80134F28.x;
    gView.at.y = gMegaStruct.D_80134F28.y;
    gView.at.z = gMegaStruct.D_80134F28.z;
    gView.rot.x = gMegaStruct.D_80134F34.x;
    gView.rot.y = gMegaStruct.D_80134F34.y;
    gView.rot.z = gMegaStruct.D_80134F34.z;
    gView.dist = gMegaStruct.D_80134F40;
    if (D_8016E134 == 1) {
        gView.eye.x = gMegaStruct.D_80134F44.x;
        gView.eye.y = gMegaStruct.D_80134F44.y;
        gView.eye.z = gMegaStruct.D_80134F44.z;
    }
}

void func_8008B0F4(void) {
    s32 sp1C;
    f32 var_f18;

    if (D_80134C1A == 0) {
        gMegaStruct.D_80134F74 = 0.0f;
        D_80134C1A = -1;
    } else if (D_80134C1A != -1) {
        D_80134C1A -= 1;
    }
    if (D_80134C1C == 0) {
        gMegaStruct.D_80134F50.x = 0.0f;
        gMegaStruct.D_80134F50.y = 0.0f;
        gMegaStruct.D_80134F50.z = 0.0f;
        D_80134C1C = -1;
    } else if (D_80134C1C != -1) {
        D_80134C1C -= 1;
    }
    if (D_80134C1E == 0) {
        gMegaStruct.D_80134F5C.x = 0.0f;
        gMegaStruct.D_80134F5C.y = 0.0f;
        D_80134C1E = -1;
    } else if (D_80134C1E != -1) {
        D_80134C1E -= 1;
    }
    if (D_8016E134 == 0) {
        gMegaStruct.D_80134F34.x = Math_WrapAngle(gMegaStruct.D_80134F34.x, gMegaStruct.D_80134F5C.x);
        gMegaStruct.D_80134F34.y = Math_WrapAngle(gMegaStruct.D_80134F34.y, gMegaStruct.D_80134F5C.y);
        gMegaStruct.D_80134F40 = gMegaStruct.D_80134F40 + gMegaStruct.D_80134F74;
        if (gMegaStruct.D_80134FA4.unk0 == 0) {
            gMegaStruct.D_80134F28.x += gMegaStruct.D_80134F50.x;
            gMegaStruct.D_80134F28.y = gMegaStruct.D_80134F28.y + gMegaStruct.D_80134F50.y;
            gMegaStruct.D_80134F28.z = gMegaStruct.D_80134F28.z + gMegaStruct.D_80134F50.z;
        } else {
            sp1C = D_80134D48[gMegaStruct.D_80134FA8].ObjectID;
            gMegaStruct.D_80134F28.x = gObjects[sp1C].Pos.x;
            gMegaStruct.D_80134F28.y = gObjects[sp1C].Pos.y + (f32) gMegaStruct.D_80134FA4.unk2;
            gMegaStruct.D_80134F28.z = gObjects[sp1C].Pos.z;
        }
    } else {
        if (D_80134C20 == 0) {
            gMegaStruct.D_80134F68.x = 0.0f;
            gMegaStruct.D_80134F68.y = 0.0f;
            gMegaStruct.D_80134F68.z = 0.0f;
            D_80134C20 = -1;
        } else if (D_80134C20 != -1) {
            D_80134C20 -= 1;
        }
        gMegaStruct.D_80134F44.x = gMegaStruct.D_80134F44.x + gMegaStruct.D_80134F68.x;
        gMegaStruct.D_80134F44.y = gMegaStruct.D_80134F44.y + gMegaStruct.D_80134F68.y;
        gMegaStruct.D_80134F44.z = gMegaStruct.D_80134F44.z + gMegaStruct.D_80134F68.z;
        if (gMegaStruct.D_80134FA4.unk0 == 1) {
            sp1C = D_80134D48[gMegaStruct.D_80134FA8].ObjectID;
            gMegaStruct.D_80134F28.x = gObjects[sp1C].Pos.x;
            gMegaStruct.D_80134F28.y = gObjects[sp1C].Pos.y + (f32) gMegaStruct.D_80134FA4.unk2;
            gMegaStruct.D_80134F28.z = gObjects[sp1C].Pos.z;
        } else {
            gMegaStruct.D_80134F28.x += gMegaStruct.D_80134F50.x;
            gMegaStruct.D_80134F28.y = gMegaStruct.D_80134F28.y + gMegaStruct.D_80134F50.y;
            gMegaStruct.D_80134F28.z = gMegaStruct.D_80134F28.z + gMegaStruct.D_80134F50.z;
        }
    }
}

void func_8008B5D4(s16* arg0) {
    gMegaStruct.D_80134F74 = ((f32) arg0[0] - gMegaStruct.D_80134F40) / (f32) arg0[1];
    D_80134C1A = arg0[1];
}

void func_8008B624(s16* arg0) {
    gMegaStruct.D_80134F50.x = ((f32) arg0[0] - gMegaStruct.D_80134F28.x) / (f32) arg0[3];
    gMegaStruct.D_80134F50.y = ((f32) arg0[1] - gMegaStruct.D_80134F28.y) / (f32) arg0[3];
    gMegaStruct.D_80134F50.z = ((f32) arg0[2] - gMegaStruct.D_80134F28.z) / (f32) arg0[3];
    D_80134C1C = arg0[3] - 1;
}

void func_8008B6E0(s16* arg0) {
    if (arg0[3] == 0) {
        if ((f32) (arg0[0]) / 10 < gMegaStruct.D_80134F34.x) {
            gMegaStruct.D_80134F5C.x = ((((f32) (arg0[0]) / 10) - gMegaStruct.D_80134F34.x) + 360) / arg0[2];
        } else {
            gMegaStruct.D_80134F5C.x = ((((f32) (arg0[0]) / 10) - gMegaStruct.D_80134F34.x)) / arg0[2];
        }
    } else if ((f32) (arg0[0]) / 10 <= gMegaStruct.D_80134F34.x) {
        gMegaStruct.D_80134F5C.x = ((((f32) (arg0[0]) / 10) - gMegaStruct.D_80134F34.x)) / arg0[2];
    } else {
        gMegaStruct.D_80134F5C.x = ((gMegaStruct.D_80134F34.x - ((f32) (arg0[0]) / 10) + 360) / arg0[2]) * -1;
    }

    if (arg0[4] == 0) {
        if ((f32) (arg0[1]) / 10 < gMegaStruct.D_80134F34.y) {
            gMegaStruct.D_80134F5C.y = ((((f32) (arg0[1]) / 10) - gMegaStruct.D_80134F34.y) + 360) / arg0[2];
        } else {
            gMegaStruct.D_80134F5C.y = ((((f32) (arg0[1]) / 10) - gMegaStruct.D_80134F34.y)) / arg0[2];
        }
    } else if ((f32) (arg0[1]) / 10 <= gMegaStruct.D_80134F34.y) {
        gMegaStruct.D_80134F5C.y = ((((f32) (arg0[1]) / 10) - gMegaStruct.D_80134F34.y)) / arg0[2];
    } else {
        gMegaStruct.D_80134F5C.y = ((gMegaStruct.D_80134F34.y - ((f32) (arg0[1]) / 10) + 360) / arg0[2]) * -1;
    }

    D_80134C1E = arg0[2];
}

void func_8008BA3C(void) {
    gMegaStruct.D_80134FA0.unk0 = (s16) gCameraType;
    gMegaStruct.D_80134FA0.unk2 = (s16) D_8016E134;
    gMegaStruct.D_80134F78.x = gView.at.x;
    gMegaStruct.D_80134F78.y = gView.at.y;
    gMegaStruct.D_80134F78.z = gView.at.z;
    gMegaStruct.D_80134F84.x = gView.rot.x;
    gMegaStruct.D_80134F84.y = gView.rot.y;
    gMegaStruct.D_80134F84.z = gView.rot.z;
    gMegaStruct.D_80134F9C = gView.dist;
    gMegaStruct.D_80134F90.x = gView.eye.x;
    gMegaStruct.D_80134F90.y = gView.eye.y;
    gMegaStruct.D_80134F90.z = gView.eye.z;
}

void func_8008BB0C(void) {
    gCameraType = (s32) gMegaStruct.D_80134FA0.unk0;
    D_8016E134 = (s8) gMegaStruct.D_80134FA0.unk2;
    gView.at.x = gMegaStruct.D_80134F78.x;
    gView.at.y = gMegaStruct.D_80134F78.y;
    gView.at.z = gMegaStruct.D_80134F78.z;
    gView.rot.x = gMegaStruct.D_80134F84.x;
    gView.rot.y = gMegaStruct.D_80134F84.y;
    gView.rot.z = gMegaStruct.D_80134F84.z;
    gView.eye.x = gMegaStruct.D_80134F90.x;
    gView.eye.y = gMegaStruct.D_80134F90.y;
    gView.eye.z = gMegaStruct.D_80134F90.z;
    gView.dist = gMegaStruct.D_80134F9C;
    gMegaStruct.D_80134FA4.unk0 = 0;
    gMegaStruct.D_80134FA4.unk2 = 0;
    func_80019B7C();
}

void func_8008BC04(s16* arg0) {
    gMegaStruct.D_80134F68.x = ((f32) arg0[0] - gMegaStruct.D_80134F44.x) / (f32) arg0[3];
    gMegaStruct.D_80134F68.y = ((f32) arg0[1] - gMegaStruct.D_80134F44.y) / (f32) arg0[3];
    gMegaStruct.D_80134F68.z = ((f32) arg0[2] - gMegaStruct.D_80134F44.z) / (f32) arg0[3];
    D_80134C20 = arg0[3];
}
