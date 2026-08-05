# Review A (reconstruction fidelity): `aa_00973690` Color_LerpPackedARGB_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00973690` |
| **VA** | `0x00973690`–`0x0097376e` |
| **Body** | **222 bytes** |
| **Canonical name** | `Color_LerpPackedARGB_Inferred` |
| **Prior scaffold** | `FUN_00973690` |
| **Review date** | `2026-07-29` (W28-F dual seal) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00973690_Color_LerpPackedARGB_Inferred.md` |
| **System** | graphics / color |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Packed-color lerp helper:

| Step | Action |
|---|---|
| 1 | Clamp `t` to **[0, 1]** (`0.0` / `g_flOne`) |
| 2 | Channel-wise lerp `c0 → c1` as **0xAARRGGBB** |
| 3 | `FUN_00973590(R,G,B,A)` with **EAX=ECX dest** packs/clamps into `*dest` |

Used by motion child tint (`004b18f0` @ 0.75 toward opaque black), and two other color producers.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00973690` ≡ raw 2026-07-23 body |
| Bytes | `read_memory` — entry `sub esp,8` / `xorps`; exit `add esp,8; ret 0x0C`; `g_flOne` load |
| Bounds | body `00973690`–`0097376e` (222 B; pad `CC`) |
| Call sites | `004b1925` / `005bb070` / `00756efc` — all `LEA ECX,dest` before call |
| Callee | `FUN_00973590` (pack; not OWN) |
| Constants | `g_flOne` @ `0x00a0f2a0` = `0000803F` = **1.0f** |
| Raw / clean | `aa_00973690_*`, `Color_LerpPackedARGB_Inferred.cpp` |

**Not performed:** `disassemble_bytes`, Launcher, runtime, dual of `00973590`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ECX = dest pointer | **Confirmed** | call-site `LEA ECX`; body `mov eax,ecx` before pack |
| Stack (t, c0, c1) + **ret 0x0C** | **Confirmed** | `C2 0C 00`; three push formals |
| Clamp [0,1] via g_flOne | **Confirmed** | decompile + `read_memory` 1.0f |
| 0xAARRGGBB channel extract | **Confirmed** | `>>8/16/24` & `0xff` |
| Integer delta before float mul | **Confirmed** | decompile `(float)(int)(…)` |
| Product / PDB name | **Open** | structural `_Inferred` |
| Decompiler surface full ABI | **Partial** | omits ECX / ret width |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Clamp t | Yes |
| Extract channels | Yes |
| Lerp four floats | Yes |
| Call pack helper | Yes |
| ret 0x0C | Yes (bytes; surface silent) |

### Recovered CF

```c
// void __fastcall Color_LerpPackedARGB(uint32_t *dest, float t, uint32_t c0, uint32_t c1)  // RET 0x0C
t = clamp(t, 0.f, 1.f);
FUN_00973590(lerp_R, lerp_G, lerp_B, lerp_A); // EAX=dest
```

### Entry / exit seal

```
83 EC 08                sub esp, 8
0F 57 C0                xorps xmm0, xmm0          ; 0.0
F3 0F 10 54 24 0C       movss xmm2, [esp+0Ch]     ; t
… comiss / lea select clamp …
… channel math …
8B C1                   mov eax, ecx              ; dest → pack
E8 …                    call FUN_00973590
5F 5E 5D 5B 83 C4 08    pop*; add esp,8
C2 0C 00                ret 0x0C
```

---

## 5. Gaps / open

1. Product English / original name.
2. Full dual of pack helper `FUN_00973590` (not OWN).
3. Runtime / bit-exact SSE rounding.

**Verdict:** **accept**
