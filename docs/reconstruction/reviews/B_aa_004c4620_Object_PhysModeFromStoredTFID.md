# Review B (skeptical / adversarial): `aa_004c4620` Object_PhysModeFromStoredTFID

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4620` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W27-G) |
| **Counterpart** | `reviews/A_aa_004c4620_Object_PhysModeFromStoredTFID.md` |
| **Scratch** | `tmp/a_004c4620.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | stdcall / stack arg | **Falsified** — `ADD ECX,0x108`; no stack load of formal |
| 2 | Mode always 10 | **Falsified** — branch returns 0xB |
| 3 | Invalid is lo==0 | **Falsified** — `(lo&hi)==~0` and `(char)w2==0` |
| 4 | Writes phys+0x28 itself | **Falsified** — pure return; no store (writer is 004c4880) |
| 5 | Has callees | **Falsified** — leaf, no CALL |
| 6 | Product mode English known | **Overstated** — constants sealed; names residual |
| 7 | Uses TFID at +0x160 | **Falsified** — block is +0x108 (family with 004c4440/004c4880) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall RET 0 | **High** | ABI break |
| Mode 0xB vs 10 | **High** | Wrong phys state |
| Predicate ≡ 004c4880 | **High** | Mode/resolve family split |
| Leaf purity | **High** | Imagined side effects |
| Product mode English | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
thiscall Object_PhysModeFromStoredTFID(this)
tfid = this+0x108
return invalid_tfid(tfid) ? 0xB : 10
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Sibling `FUN_004c4880` applies identical predicate when writing `phys+0x28`. Sibling `FUN_004c4440` uses inverse gate before resolve.

---

## 4. Surviving contract for AutoCore

```
// Phys mode from object identity block:
mode = Object_PhysModeFromStoredTFID(obj);  // 0xB or 10
// When applying TFID client-side, mode must match this leaf (see Object_SetTFID_ApplyPhysMode_Rebind)
// 0xB = unassigned TFID; 10 = assigned — product enum names residual
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/modes/predicate sealed; product English residual only → **accept**.
