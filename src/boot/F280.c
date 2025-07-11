#include "prevent_bss_reordering2.h"
#include <ultra64.h>
#include "F280.h"
//.bss
Matrix D_800557E0;
s32 D_80055820;
Matrix D_80055828[20];
UNUSED s32 BssPad_80055d28;
u32 D_80055D30[3];
u32 D_80055D40[3];
s32 D_80055D4C;

//.data
s32 D_8004A390 = FALSE;
s32 D_8004A394 = FALSE;

//s32 func_8000E944(Gfx** gfx, struct UnkInnerStruct8000E944* arg1, s32 arg2, s32 arg3, s32 arg4, Gfx* arg5, s32 arg6, s32 arg7);

void Math_Mat3f_Inverse(Matrix mf, Matrix mf1) {
    f32 determinant;
    f32 m00 = mf1[0][0];
    f32 m10 = mf1[1][0];
    f32 m20 = mf1[2][0];
    f32 m01 = mf1[0][1];
    f32 m11 = mf1[1][1];
    f32 m21 = mf1[2][1];
    f32 m02 = mf1[0][2];
    f32 m12 = mf1[1][2];
    f32 m22 = mf1[2][2];

    determinant = ((m00 * m11 * m22) + (m10 * m21 * m02) + (m20 * m01 * m12)) -
                  ((m00 * m21 * m12) + (m10 * m01 * m22) + (m20 * m11 * m02));

    mf[0][0] = ((m11 * m22) - (m21 * m12)) / determinant;
    mf[1][0] = ((m20 * m12) - (m10 * m22)) / determinant;
    mf[2][0] = ((m10 * m21) - (m20 * m11)) / determinant;
    mf[0][1] = ((m21 * m02) - (m01 * m22)) / determinant;
    mf[1][1] = ((m00 * m22) - (m20 * m02)) / determinant;
    mf[2][1] = ((m20 * m01) - (m00 * m21)) / determinant;
    mf[0][2] = ((m01 * m12) - (m11 * m02)) / determinant;
    mf[1][2] = ((m10 * m02) - (m00 * m12)) / determinant;
    mf[2][2] = ((m00 * m11) - (m10 * m01)) / determinant;
}

s32 func_8000E944(Gfx** gfx, UnkStruct_F280_1* arg1, s32 arg2, s32 arg3, s32 arg4, Gfx* arg5, s32 arg6, s32 arg7) {
    s32 i;
    s32 j;
    Gfx* dlist;
    Vec3f* sp90;
    Vec3f* sp8C;
    Vec3f* sp88;
    UnkStruct_F280* sp84;
    Matrix mf;
    UNUSED char pad[4];
    s32 sp3C;

    sp3C = 0;
    sp84 = (UnkStruct_F280*)((u32)arg1 + (u32)arg5);
    dlist = *gfx;
    guMtxIdentF(mf);

    for (i = 0; i < 3; i++) {
        switch (D_80055D30[i]) { /* irregular */
            case 17:
                sp90 = &sp84[arg6].unk4;
                if ((sp90->x != 0.0f) || (sp90->y != 0.0f) || (sp90->z != 0.0f)) {
                    func_80013AE0((float*)mf, sp90->x, sp90->y, sp90->z);
                    sp3C = 1;
                }
                break;
            case 19:
                sp8C = &sp84[arg6].unk10;
                if ((sp8C->x != 0.0f) || (sp8C->y != 0.0f) || (sp8C->z != 0.0f)) {
                    for (j = 0; j < 3; j++) {
                        switch (D_80055D40[j]) {
                            case 0x33:  
                                Math_Mat3f_RotatePitch((float*)mf, sp8C->x); // Pitch rotation
                                break;
                            case 0x34: 
                                Math_Mat3f_RotateYaw((float*)mf, sp8C->y); // Yaw rotation
                                break;
                            case 0x35:
                                Math_Mat3f_RotateRoll((float*)mf, sp8C->z); // Roll rotation
                                break;
                        }
                    }
                    sp3C = 1;
                }
                break;
            case 21:
                sp88 =  &sp84[arg6].unk1C;
                if ((sp88->x != 1.0f) || (sp88->y != 1.0f) || (sp88->z != 1.0f)) {
                    Math_Mat3f_Scale((float*)mf, sp88->x, sp88->y, sp88->z);
                    sp3C = 1;
                }
                break;
        }
    }

    if (sp3C != 0) {
        D_80055820 += 1;
        guMtxCatF(mf, D_80055828[D_80055820 - 1], D_80055828[D_80055820]);
    }
    guMtxF2L(D_80055828[D_80055820], &D_8016E104->unkE0[arg7]);

    gSPMatrix(dlist++, osVirtualToPhysical(&D_8016E104->unkE0[arg7++]), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if (sp84[arg6].unk0 >= 0) {
        arg7 = func_8000EEE8(&dlist, arg1, arg2, arg3, arg4, sp84[arg6].unk0, arg7);
    }
    // ok but why load into a temp.
    if ((i = sp84[arg6].unk2C) != 0) {
        arg7 = func_8000E944(&dlist, arg1, arg2, arg3, arg4, arg5, arg6 + i, arg7);
    }
    if (sp3C != 0) {
        D_80055820 -= 1;
    }
    if ((i = sp84[arg6].unk28) != 0) {
        arg7 = func_8000E944(&dlist, arg1, arg2, arg3, arg4, arg5, arg6 + i, arg7);
    }
    *gfx = dlist;
    return arg7;
}

s32 func_8000EEE8(Gfx** gfx, UnkStruct_F280_1* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    struct UnkInputStruct8000EEE8_SPEC* spEC;
    Gfx* dlist;
    struct UnkInputStruct8000EEE8_SPE4* spE4;
    Matrix spA4;
    s32 spA0;

    spA0 = 0;
    spE4 = &arg1->unk8;
    spEC = &arg1->unkC;
    dlist = *gfx;
    guMtxIdentF(spA4);

    gSPSegment(dlist++, spE4->unk0, OS_PHYSICAL_TO_K0(arg1));
    gSPSegment(dlist++, spE4->unk1, OS_PHYSICAL_TO_K0(arg2));
    gSPSegment(dlist++, spE4->unk2, OS_PHYSICAL_TO_K0(arg3));
    gSPSegment(dlist++, spE4->unk3, OS_PHYSICAL_TO_K0(arg4));
    gDPPipelineMode(dlist++, G_PM_1PRIMITIVE);

    if ((spEC[arg5].unk0 == 0) || (spEC[arg5].unk0 == 5) || (spEC[arg5].unk0 == 6) || (spEC[arg5].unk0 == 8)) {
        switch (spEC[arg5].unk0) { /* irregular */
            case 5:
                guMtxIdentF(D_800557E0);
                Math_Mat3f_Inverse(D_800557E0, D_80055828[D_80055820]);
                Math_Mat3f_Scale((float*)D_800557E0, D_8016E3B4, D_8016E3BC, D_8016E3C4);
                D_80055820 += 1;
                guMtxCatF(D_800557E0, D_80055828[D_80055820 - 1], D_80055828[D_80055820]);
                spA0 += 1;
                break;
            case 6:
                D_8004A390 = TRUE;
                gDPSetTextureLUT(dlist++, G_TT_NONE);
                gSPSetGeometryMode(dlist++, G_TEXTURE_GEN);
                gSPTexture(dlist++, 0x07C0, 0x07C0, 0, G_TX_RENDERTILE, G_ON);
                gDPSetTexturePersp(dlist++, G_TP_PERSP);
                gDPSetPrimColor(dlist++, 0, 0, 255, 255, 255, 255);
                gDPSetEnvColor(dlist++, 64, 64, 64, 255);
                gDPSetCombineMode(dlist++, G_CC_HILITERGBA, G_CC_HILITERGBA);
                gDPLoadTextureBlock(dlist++, D_1000768, G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                    G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
                gDPSetHilite1Tile(dlist++, G_TX_RENDERTILE, &D_8016E104->hilites[0], 32, 32);
                break;
            case 8:
                D_8004A394 = TRUE;
                gSPSetGeometryMode(dlist++, G_TEXTURE_GEN);
                break;
            default:
                if (D_8004A390) {
                    gSPClearGeometryMode(dlist++, G_TEXTURE_GEN);
                    gSPTexture(dlist++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
                    D_8004A390 = FALSE;
                } else if (D_8004A394) {
                    gSPClearGeometryMode(dlist++, G_TEXTURE_GEN);
                    D_8004A394 = FALSE;
                }
                break;
        }
        if (spEC[arg5].u.unk4_as_f != 1.0f) {
            Math_Mat3f_Scale((float*)spA4, spEC[arg5].u.unk4_as_f, spEC[arg5].u.unk4_as_f, spEC[arg5].u.unk4_as_f);
            D_80055820 += 1;
            guMtxCatF(spA4, D_80055828[D_80055820 - 1], D_80055828[D_80055820]);
            spA0 += 1;
        }
        guMtxF2L(D_80055828[D_80055820], &D_8016E104->unkE0[arg6]);
        gSPMatrix(dlist++, osVirtualToPhysical(&D_8016E104->unkE0[arg6++]),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(dlist++, (s32) (spEC[arg5].dlist) + (u8*)arg1);
        D_80055820 -= spA0;
    } else if (spEC[arg5].unk0 == 1) {
        arg6 = func_8000E944(&dlist, arg1, arg2, arg3, arg4, spEC[arg5].dlist, spEC[arg5].u.unk4_as_s, arg6);
    }
    *gfx = dlist;
    return arg6;
}

s32 func_8000F888(UnkStruct_8000F888* arg0, Gfx** arg1, s32 arg2, UNUSED s32 arg3, UNUSED s32* unused, s32* arg5) {
    Vec3f* sp84;
    Vec3f* sp80;
    Vec3f* sp7C;
    Gfx* sp78;
    Matrix sp38;
    UNUSED s32 pad;
    s32 sp30;
    s32 sp2C;
    s32 sp28;

    sp28 = 0;
    sp78 = *arg1;

    guMtxIdentF(sp38);
    for (sp30 = 0; sp30 < 3; sp30++) {
        switch (D_80055D30[sp30]) { /* irregular */
            case 17:
                sp84 = &arg0->unk0;
                if ((sp84->x != 0.0f) || (sp84->y != 0.0f) || (sp84->z != 0.0f)) {
                    func_80013AE0((float*)&sp38, sp84->x, sp84->y, sp84->z);
                    sp28 = 1;
                }
                break;
            case 19:
                sp80 = (void*) ((u32) arg0 + 0xC);
                if ((sp80->x != 0.0f) || (sp80->y != 0.0f) || (sp80->z != 0.0f)) {
                    for (sp2C = 0; sp2C < 3; sp2C++) {
                        switch (D_80055D40[sp2C]) { /* switch 1; irregular */
                            case 0x33:              /* switch 1 */
                                Math_Mat3f_RotatePitch((float*)sp38, sp80->x);
                                break;
                            case 0x34: /* switch 1 */
                                Math_Mat3f_RotateYaw((float*)sp38, sp80->y);
                                break;
                            case 0x35: /* switch 1 */
                                Math_Mat3f_RotateRoll((float*)sp38, sp80->z);
                                break;
                        }
                    }
                    sp28 = 1;
                }
                break;
            case 21:
                sp7C = (void*) ((u32) arg0 + 0x18);
                if ((sp7C->x != 1.0f) || (sp7C->y != 1.0f) || (sp7C->z != 1.0f)) {
                    Math_Mat3f_Scale((float*)sp38, sp7C->x, sp7C->y, sp7C->z);
                    sp28 = 1;
                }
                break;
        }
    }
    if (sp28 != 0) {
        D_80055820 += 1;
        guMtxCatF(sp38, D_80055828[D_80055820 - 1], D_80055828[D_80055820]);
    }
    *arg1 = sp78;
    *arg5 = sp28;
    return arg2;
}

s32 func_8000FC08(struct UnkInputStruct8000FC08* arg0, Gfx** arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 sp34;
    Gfx* sp30;
    s32 sp2C;

    sp30 = *arg1;
    arg6 = func_8000F888((void*) ((u32) arg0 + 0x14), &sp30, arg6, arg2, arg0->unk0, &sp2C);
    if (arg0->unk0 >= 0) {
        arg6 = func_8000EEE8((Gfx**) &sp30, arg2, arg3, arg4, arg5, (s32) arg0->unk0, arg6);
    }
    if (arg0->unk10 != 0) {
        for (sp34 = 0; sp34 < arg0->unk10; sp34++) {
            arg6 = func_8000FC08(arg0->unkC[sp34], &sp30, arg2, arg3, arg4, arg5, arg6);
        }
    }
    if (sp2C != 0) {
        D_80055820 -= 1;
    }
    *arg1 = sp30;
    return arg6;
}

s32 func_8000FD9C(struct UnkInputStruct8000FC08* arg0, Gfx** arg1, UnkStruct_F280_1* arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    D_80055820 = 0;
    guMtxL2F(D_80055828[D_80055820], (Mtx*) &D_8016E104->unk00[1]);
    if (arg0->unk0 == 0) {
        arg6 = func_8000EEE8(arg1, arg2, arg3, arg4, arg5, arg0->unk28, arg6);
    } else if (arg0->unk0 == 1) {
        arg6 = func_8000FC08(arg0->unk28, arg1, arg2, arg3, arg4, arg5, arg6);
    }
    return arg6;
}
