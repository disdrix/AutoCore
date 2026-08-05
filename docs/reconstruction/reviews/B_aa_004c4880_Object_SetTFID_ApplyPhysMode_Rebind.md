# Review B (skeptical / adversarial): `aa_004c4880` Object_SetTFID_ApplyPhysMode_Rebind

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4880` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W26-F) |
| **Counterpart** | `reviews/A_aa_004c4880_Object_SetTFID_ApplyPhysMode_Rebind.md` |
| **Scratch** | `tmp/a_004c4880.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | cdecl / no stack formal | **Falsified** — `RET 4`; loads `[esp+4]` as source |
| 2 | Mode always 10 | **Falsified** — branch writes 0xB when invalid TFID |
| 3 | Invalid test is `==0` on lo only | **Falsified** — `(lo&hi)==~0` **and** `(char)w2==0` |
| 4 | Does not touch phys child | **Falsified** — requires `this+8` and writes `+0x28` |
| 5 | Leaf / no rebind | **Falsified** — CALL `0x00560e90` |
| 6 | Product name is retail string | **Overstated** — no plate string; name inferred from TFID siblings + callee |
| 7 | Decompiler shows full manager thiscall | **Residual** — surface omits manager ECX; bytes rebuild manager chain (documented; matches 00560e90 dual) |
| 8 | Copies 8 B only (COID pair) | **Falsified** — four dwords to +0x108..+0x114 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + RET 4 | **High** | ABI break |
| TFID 16 B store | **High** | Wrong identity field width |
| Mode predicate ≡ 004c4620 | **High** | Wrong phys state after assign |
| Rebind side effect | **High** | Stale world links |
| Product mode English | **Medium** | Naming only |
| Manager chain detail | **Medium-High** | Mis-port of 00560e90 args |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
thiscall Object_SetTFID_ApplyPhysMode_Rebind(this, src[4])
memcpy this+0x108 ← src (16 B)
if phys=*(this+8):
  mode = invalid_tfid ? 0xB : 10
  *(phys+0x28) = mode
  WorldObj_RebindActivate(manager, phys)  // flag slot = 1
RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Sole caller `FUN_00626890` post-resolve. Sibling `FUN_004c4620` pure mode; `FUN_004c4440` TFID field names.

---

## 4. Surviving contract for AutoCore

```
// After assigning object identity (TFID/COID block):
Object_SetTFID_ApplyPhysMode_Rebind(obj, tfid16);
// phys+0x28 becomes 0xB if TFID unassigned, else 10; world rebind follows
// Do not skip rebind when porting client phys attach after COID apply
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/TFID/mode/rebind sealed; product mode English residual only → **accept**.
