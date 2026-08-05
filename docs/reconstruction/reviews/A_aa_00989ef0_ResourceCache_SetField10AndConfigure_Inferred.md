# Review A (reconstruction fidelity): `aa_00989ef0` ResourceCache_SetField10AndConfigure_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00989ef0` |
| **VA** | `0x00989ef0`–`0x00989f58` (**105 B**) |
| **Canonical name** | `ResourceCache_SetField10AndConfigure_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_00989ef0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-F) |
| **Counterpart** | `reviews/B_aa_00989ef0_ResourceCache_SetField10AndConfigure_Inferred.md` |
| **System** | ResourceCache / guarded resource host |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 105 B) + `analyze_function_complete`; callers; layout pair with `00989e00` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Optional-CS write of object `+0x10` from ECX, then configure embedded subobject at `+0x14` via `FUN_00996d70(stack_flag)`. SEH-framed.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00989ef0_FUN_00989ef0.md` (+ 2026-07-29 W31-F append) |
| Annotated | `docs/reconstruction/raw/aa_00989ef0_FUN_00989ef0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ResourceCache_SetField10AndConfigure_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00989ef0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00989ef0_FUN_00989ef0.md` |
| Named record | `docs/reconstruction/functions/aa_00989ef0_ResourceCache_SetField10AndConfigure_Inferred.md` |
| Sibling | `ResourceCache_LookupByName` (`0x00989e00`) same CS/flag |
| Live | decompile ≡ raw CF; full body hex; `RET 4` |

---

## 3. Signature (sealed)

```c
// EDI=object; ECX=field10; stack configureFlag; RET 4; void
void ResourceCache_SetField10AndConfigure_Inferred(
    void* obj /*EDI*/,
    uint32_t field10 /*ECX*/,
    uint32_t configureFlag /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| object | **EDI** (`[EDI+…]` CS/flag/field; callers set EDI) | **High** |
| field10 | **ECX** (`MOV EBX,ECX` → `[EDI+0x10]`) | **High** |
| configureFlag | stack formal (`RET 4`) | **High** |
| cleanup | **`RET 4`** (`C2 04 00`) | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
SEH install (LAB_009adcf3)
if flag+0x80: EnterCS(+0x68)
obj+0x10 = ECX
FUN_00996d70(stack) with EAX = obj+0x14
if flag+0x80: LeaveCS(+0x68)
SEH unlink; RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Optional CS enter/leave | **Yes** | **High** |
| Store field10 | **Yes** | **High** |
| Configure subobject `+0x14` | **Yes** (LEA EAX) | **High** |
| SEH frame | **Yes** | **High** |
| RET 4 | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body (105 B):

```
6A FF 68 F3 DC 9A 00 64 A1 00 00 00 00 50 64 89
25 00 00 00 00 51 80 BF 80 00 00 00 00 53 56 8D
77 68 8B D9 89 74 24 08 74 07 56 FF 15 BC 61 9C
00 8B 44 24 1C 50 C7 44 24 18 00 00 00 00 8D 47
14 89 5F 10 E8 37 CE 00 00 80 7E 18 00 74 07 56
FF 15 B8 61 9C 00 8B 4C 24 0C 5E 5B 64 89 0D 00
00 00 00 83 C4 10 C2 04 00
```

Key: flag `+0x80`, CS `+0x68`, store `+0x10`, LEA `+0x14`, IAT Enter `0x009C61BC` / Leave `0x009C61B8`.

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| EDI + ECX + RET 4 ABI | **High** | bytes + call sites |
| CS family with `00989e00` | **High** | same offsets |
| Subobject configure | **High** | LEA EAX |
| ResourceCache product class | **Inferred** | layout + global `0x00d1eac8` |
| Meaning of field10 | **Open** | size-like at AssManager |

---

## 7. Gaps

1. Product name for `+0x10` / configure flag semantics.
2. Full CF of `FUN_00996d70` and nested helpers (not OWN).
3. SEH unwind `LAB_009adcf3` Leave guarantees.
4. Runtime / bit-exact.

**Verdict:** ABI/CF/lock sealed; configure residual + product English → **accept-with-gaps**.
