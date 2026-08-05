# Review A (reconstruction fidelity): `aa_004332e0` NDAssetImage_FlipVertical

| Field | Value |
|---|---|
| **Stable ID** | `aa_004332e0` |
| **VA** | `0x004332e0`–`0x0043382` |
| **Canonical name** | `NDAssetImage_FlipVertical` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (pixel-buffer vertical flip) |
| **Counterpart** | `reviews/B_aa_004332e0_NDAssetImage_FlipVertical.md` |
| **System** | client assets / `NDAssetImage` (TGA normalize) |
| **Verdict** | **accept-with-gaps** (CF + layout High; product pitch/width naming Probable) |

---

## 1. Purpose

**In-place vertical flip** of the `NDAssetImage` pixel buffer held at `this+0x1b0`.

Allocates a same-size temp (`pitch * height`), copies rows **bottom→top** into the temp (source starts at last row, dest walks from first), then `free`s the old buffer and installs the temp. Used so **GetPixel y=0 is always image bottom** after top-origin TGA loads (`NDAssetImage_LoadTGA` plate: top-origin bit5 + 32bpp → call this).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004332e0_NDAssetImage_FlipVertical.md` |
| Annotated | `docs/reconstruction/raw/aa_004332e0_NDAssetImage_FlipVertical.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDAssetImage_FlipVertical.cpp` |
| Function record | `docs/reconstruction/functions/aa_004332e0_NDAssetImage_FlipVertical.md` |
| Caller plate | `raw/aa_004347d0_NDAssetImage_LoadTGA.md` (calls after decode when top-origin + 32bpp) |
| Sibling caller | `FUN_0098ae80` / `reconstructed-exact/FUN_0098ae80.cpp` (post row-copy flip) |
| Live Ghidra | `decompile_function` `0x004332e0`; `analyze_function_complete`; `get_function_callers`; `read_memory` body 180 B |

---

## 3. Signature / convention

```c
// this in EBX (decompiler: unaff_EBX); no stack args; plain RET
// Return: AL = 1 success, AL = 0 fail (null buffer / malloc fail)
uint8_t /* bool in AL */ NDAssetImage_FlipVertical(/* NDAssetImage* this in EBX */);
```

| Item | Evidence |
|---|---|
| `this` | All field loads via `EBX+disp` (`[EBX+0x1b0]`, `[EBX+0xc]`, `[EBX+0x10]`); no stack `this` |
| Args | `parameters: []` (`analyze_function_complete`) |
| Epilogue | `ADD ESP,8` / `RET` — locals only; **not** `RET n` |
| Return | Fail: `XOR AL,AL`; success: `MOV AL,1` then `RET` |
| Callees | `malloc` IAT `@0x009c6528`, `free` IAT `@0x009c6524` only |
| Callers | `NDAssetImage_LoadTGA` `@0x004347d0`, `FUN_0098ae80` `@0x0098ae80` (xrefs `00434a93`, `0098af31`) |

---

## 4. Object fields (this)

| Offset | Role | Confidence |
|---|---|---|
| `+0x0c` | **Row pitch in bytes** (stride; not necessarily pixel width) | **High** — `IMUL` size, `REP MOVS*` count, per-row `SUB`/`ADD` |
| `+0x10` | **Height in rows** | **High** — loop bound `CMP ESI,[EBX+0x10]` |
| `+0x1b0` | **Pixel buffer pointer** (`void*` / byte*) | **High** — null gate, source base, free+replace |

Allocation: `malloc(*(int*)(this+0xc) * *(int*)(this+0x10))` → **pitch × height** bytes.

---

## 5. Control flow (sealed)

```
if *(this+0x1b0) == 0:          return 0
tmp = malloc(pitch * height)
if tmp == 0:                    return 0
src = (height-1)*pitch + buffer   // last row
dst = tmp
for row = 0 .. height-1:
  copy pitch bytes: REP MOVSD (pitch>>2) + REP MOVSB (pitch&3)
  src -= pitch                    // walk up source
  dst += pitch                    // walk down dest
free(old buffer)
*(this+0x1b0) = tmp
return 1
```

Height ≤ 0: loop skipped (`JLE`); still frees old and installs empty/same-size tmp if malloc succeeded.

---

## 6. Machine bytes (`read_memory` @ `0x004332e0`, body through `RET`)

```
83 EC 08                 SUB  ESP, 8
83 BB B0 01 00 00 00     CMP  dword [EBX+0x1b0], 0
75 06                    JNZ  have_buf
32 C0                    XOR  AL, AL
83 C4 08                 ADD  ESP, 8
C3                       RET
8B 43 0C                 MOV  EAX, [EBX+0x0C]     ; pitch
0F AF 43 10              IMUL EAX, [EBX+0x10]     ; * height
57                       PUSH EDI
50                       PUSH EAX
FF 15 28 65 9C 00        CALL [0x009c6528]        ; malloc
...
F3 A5                    REP MOVSD                ; dword bulk
...
F3 A4                    REP MOVSB                ; tail bytes
...
FF 15 24 65 9C 00        CALL [0x009c6524]        ; free
89 BB B0 01 00 00        MOV  [EBX+0x1b0], EDI    ; install tmp
B0 01                    MOV  AL, 1
5F                       POP  EDI
83 C4 08                 ADD  ESP, 8
C3                       RET
```

Hex (function through pad):  
`83ec0883bbb001000000750632c083c408c38b430c0faf43105750ff1528659c00…b0015f83c408c3`  
Decompile ≡ bytes. **No conflict.** Clean scaffold preserves the same CF (decompiler dword/byte loops ≡ `REP MOVSD`/`MOVSB`).

---

## 7. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Vertical row reverse of `+0x1b0` buffer | **High** | Last-row start, pitch step down |
| `+0x0c` = byte pitch, `+0x10` = height | **High** | Size + copy + step math |
| Return 0/1 in AL | **High** | `XOR AL` / `MOV AL,1` |
| `this` in EBX | **High** | All field access; callers must set EBX |
| Only malloc/free callees | **High** | analyze + IAT sites |
| Callers LoadTGA + FUN_0098ae80 | **High** | xrefs |
| Top-origin TGA normalize purpose | **High** (semantic) | LoadTGA plate bit5 + 32bpp |
| `+0x0c` always `width*bpp` | **Probable** | No bpp field read in this unit |
| Full NDAssetImage layout beyond these 3 | **Tentative** | Own-VA only |
| Bit-for-bit / live runtime flip | **Open** | Deferred |

---

## 8. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null buffer → 0 | **Yes** |
| malloc(pitch×height) fail → 0 | **Yes** |
| Bottom-to-top row copy + free/replace → 1 | **Yes** |
| REP dword/byte bulk ≡ decompiler loops | **Yes** |

Scaffold cleanliness: clean still uses Ghidra names (`unaff_EBX`, `puVar*`) and a misleading `uint32_t /* width */` return annotation — **behavior OK**, naming residual.

---

## 9. Gaps / open

1. Exact product type of `+0x0c` when bpp ≠ 32 (LoadTGA only flips 32bpp path).
2. Whether any non-TGA caller expects flip of other channel layouts.
3. Rename clean plate (`this`, `pitch`, `height`, `bool` return) without CF change.
4. Runtime / differential image test deferred.

**Verdict:** **accept-with-gaps**
