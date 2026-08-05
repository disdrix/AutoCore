# Review B (skeptical / adversarial): `aa_0076f6e0` Math_Mat4TransformPoint3_Project

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076f6e0` |
| **VA** | `0x0076f6e0` |
| **Canonical name** | `Math_Mat4TransformPoint3_Project` (structural) |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0076f6e0_Math_Mat4TransformPoint3_Project.md` |
| **System** | graphics / math |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always divides by w | Branches; copies xyz when w≈1 or w≈0 | **Falsified** always-divide |
| 2 | Takes vec4 input | Seeds **w=1** from xyz only (`EAX[0..2]`) | **Falsified** vec4-in |
| 3 | Writes homogeneous w to out | Only three stores to EBX | **Falsified** |
| 4 | Stack cdecl `(m,in,out)` | EAX/ESI/EBX register ABI at `00972fbf` | **Falsified** |
| 5 | This owns the matrix multiply | Only callee is `FUN_0076f240` | **Attack fails** — mul is callee |
| 6 | Divides even when w=0 | Gate requires `w >= eps \|\| w <= -eps` | **Falsified** zero-w divide |
| 7 | Ghidra `void FUN_0076f6e0(void)` is complete API docs | Hides register formals | **Overstated** plate |
| 8 | Product name required | No strings | **Agree structural** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Point (w=1) × M + conditional /w | **Confirmed** | Wrong clip-space projection |
| EAX/ESI/EBX ABI | **Confirmed** | Register corruption |
| No out.w write | **Confirmed** | Caller buffer overrun if assumed 16 B |
| Near-zero w safety | **Confirmed** | Inf/NaN in ports |
| Product name | **Open** | Naming |

---

## 3. Cross-check against raw / live / bytes

```
raw ≡ live decompile.
read_memory @ 0x0076f6e0:
  MOVSS from [EAX], [EAX+4], [EAX+8]
  MOV dword [local.w], 0x3f800000
  CALL 0x0076f240
  FLD w; FSUB g_flOne; FABS; FCOMIP vs DAT_00a240ec (1e-6)
  JNC skip_divide → copy path
  else inv*w path stores to [EBX], [EBX+4], [EBX+8]
xrefs: 18
```

### Call-site contract (`0x00972fbf`)

```
; node in EAX after optional FUN_00972e50 dirty rebuild
MOV  ESI, EAX          ; matrix lives on/with node (same ptr after compose path)
LEA  EBX, [ESP+0x14]  ; out xyz
MOV  EAX, [ESP+0x24]  ; in xyz
CALL Math_Mat4TransformPoint3_Project
```

### Trap

Do **not** merge this with `Math_Mat4MulVec4_AffineFast` — this always treats input as a **point** (w=1) and returns **euclidean** xyz after optional divide. Direction vectors must call the mul helper with w=0 instead.

---

## 4. Surviving contract for AutoCore

```
Math_Mat4TransformPoint3_Project(in /*EAX*/, m /*ESI*/, out /*EBX*/)
  p = (in.x, in.y, in.z, 1)
  p = Mat4MulVec4_AffineFast(p)   // via FUN_0076f240
  if |p.w-1| large enough and |p.w| >= 1e-6:
    out = p.xyz / p.w
  else:
    out = p.xyz
```

---

## 5. Residual after dual

| Item | Status |
|------|--------|
| CF / ABI / project gate | **Sealed Confirmed** |
| Product name | Open |
| Runtime | Open |

**Verdict:** accept-with-gaps.
