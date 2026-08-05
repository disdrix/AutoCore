# Review B (skeptical / adversarial): `aa_0043d770` StdMap_EraseEq_UintKey_Isnil15_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d770` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W38-O) |
| **Counterpart** | `reviews/A_aa_0043d770_StdMap_EraseEq_UintKey_Isnil15_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall map (like many peers) | **Falsified** — entry `MOV EDI,EAX`; map from **EAX** |
| 2 | Stack formals / `RET 4` / `RET 8` / `RET 0xC` | **Falsified** — bare `C3` after `ADD ESP,0xC` local frame |
| 3 | Val12 isnil@+0x19 erase family | **Falsified** — callees use isnil@**+0x15** (`*(char*)(node+0x15)`) |
| 4 | Find-only / no mutation | **Falsified** — calls erase-range `00439050` after count |
| 5 | Returns void / iterator only | **Falsified** — `MOV EAX,ESI` count after loop |
| 6 | Scaffold assPreloader product name | **Rejected** — structural StdMap erase name; caller is AssPreloader only |
| 7 | Same register ABI as insert peer `0043d700` | **Partial** — insert uses **EDI=map, ECX=key\***; erase uses **EAX=map, ECX=key\*** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX map + ECX key* + plain RET + count | **High** | Caller ABI crash / wrong tree |
| equal_range → count → erase order | **High** | Missed erases / wrong count |
| isnil@+0x15 / key@+0x0C | **High** | Wrong node family port |
| Product value_type English | **Open** | Naming only |
| Multi-equal vs unique (count>1) | **Open** | Rare; AssPreloader inserts unique keys |
| Runtime | **Open** | Cache races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  equal_range; count loop; erase range; return count

bytes:
  SUB ESP,0xC; PUSH EBX,EBP,ESI,EDI
  MOV EDI,EAX; MOV EBX,ECX
  LEA EAX,[ESP+0x14]; MOV ECX,EDI; CALL 0043dc20
  count loop via 0046f100; erase via 00439050
  MOV EAX,ESI; ADD ESP,0xC; RET
```

Live decompile 2026-08-04 ≡ raw 2026-07-23 CF; **bytes win** on register ABI.

---

## 4. Surviving contract for AutoCore

```
// isnil15 uint-key erase-by-key with count:
//   EAX = map (head @ +4)
//   ECX = const uint32_t* key
//   plain RET — do NOT invent RET 4/8/C
//   returns number of nodes erased
// Do NOT use Val12 isnil@+0x19 erase helpers (004e5120 family).
// Do NOT treat as thiscall; do NOT swap with insert ABI (EDI map @ 0043d700).
// Do NOT use scaffold assPreloader-derived product name.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/layout and rejects thiscall / Val12 / void-return / scaffold-name claims → **accept**.
