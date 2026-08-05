# Review A (reconstruction fidelity): `aa_0052ada0` CVOGCharacter_GetResourceBalanceByType

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052ada0` |
| **VA** | `0x0052ada0` |
| **Canonical name** | `CVOGCharacter_GetResourceBalanceByType` (proposed / role-sealed) |
| **Prior names** | `FUN_0052ada0`; scaffold alias `Named_CalleeOf_CVOGCharacter_CheckMissionRequirements_0052ada0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + live asm seals) |
| **Counterpart** | `reviews/B_aa_0052ada0_CVOGCharacter_GetResourceBalanceByType.md` |
| **System** | `missions-progression` (also item-cost / UI balance consumers) |
| **Dual status** | **Present** (first full A+B dual) |
| **Verdict** | **accept-with-gaps** (product English open; CF/ABI/map layout sealed) |
| **Scratch** | `tmp/a_0052ada0.md` |

---

## 1. Purpose

Character **resource / currency balance lookup by type id**:

1. Treat `this` (ECX) as character.
2. Tree-find key = stack `typeId` in ordered map rooted at **`character + 0x584`** via `FUN_00418b80` (map lower-bound / find).
3. If result node equals end sentinel **`character + 0x588`** → return **`-1`** (missing type).
4. Else return **`*(int*)(node + 0x10)`** (stored balance).

**No writes.** Pure query used by `CheckMissionRequirements` Discipline gate (`mission+0x104` type / `+0x108` threshold) and many inventory/UI cost sites.

**Calling convention (asm-sealed):**

| Slot | Role | Evidence |
|------|------|----------|
| `ECX` / `this` | `CVOGCharacter*` | `MOV ESI,ECX`; loads `+0x584` / `+0x588` |
| stack0 | **type id** (`int`) | `LEA EAX,[ESP+0xc]` after two pushes → original `[ESP+4]` |
| return | **balance** or **`-1`** in `EAX` | `OR EAX,-1` / `MOV EAX,[EAX+0x10]` |
| epilogue | **`RET 4`** | `C2 04 00` both exit paths |

```c
int __thiscall CVOGCharacter_GetResourceBalanceByType(void* character /*ECX*/, int typeId);
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0052ada0_FUN_0052ada0.md` |
| Annotated | `docs/reconstruction/raw/aa_0052ada0_FUN_0052ada0.annotated.md` |
| Clean (scaffold) | `docs/reconstruction/reconstructed-exact/FUN_0052ada0.cpp` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_CVOGCharacter_CheckMissionRequirements_0052ada0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0052ada0_FUN_0052ada0.md` |
| Parent dual | `A/B_aa_005462b0_CVOGCharacter_CheckMissionRequirements` + residual `reviews/a_005462b0.md` |
| Live decompile | Ghidra `batch_decompile` `0x0052ada0` (2026-07-29) — **CF ≡ raw** |
| Live asm | `get_assembly_context` body + Requirements call site `0x00546373` |
| Live bytes | `read_memory` `0x0052ada0` length 50 |
| Map helper | `batch_decompile` `FUN_00418b80` @ `0x00418b80` (ordered-map find) |
| Xrefs | `get_function_xrefs` — **many** (Requirements + item UI / costs / tooltips) |

**Not performed:** `disassemble_bytes` bulk listing, Launcher, live balance capture, bit-exact image diff.

---

## 3. Body (authoritative asm / decompile)

### 3.1 Assembly (sealed)

```text
0052ada0  PUSH ECX                 ; local out-node slot
0052ada1  PUSH ESI
0052ada2  MOV  ESI, ECX            ; this = character
0052ada4  LEA  EAX, [ESP+0xc]      ; &typeId (stack formal)
0052ada8  PUSH EAX                 ; find key*
0052ada9  LEA  ECX, [ESP+0x8]
0052adad  PUSH ECX                 ; &out_node
0052adae  LEA  ECX, [ESI+0x584]    ; map header
0052adb4  CALL FUN_00418b80        ; ordered-map find
0052adb9  MOV  EAX, [ESP+0x4]      ; out_node
0052adbd  CMP  EAX, [ESI+0x588]    ; end sentinel
0052adc3  POP  ESI
0052adc4  JNZ  found
0052adc6  OR   EAX, 0xFFFFFFFF     ; missing → -1
0052adc9  POP  ECX
0052adca  RET  4
found:
0052adcd  MOV  EAX, [EAX+0x10]     ; balance value
0052add0  POP  ECX
0052add1  RET  4
```

### 3.2 Decompile (raw ≡ live)

```c
undefined4 __fastcall FUN_0052ada0(int param_1 /* this */)
{
  int local_4;
  local_4 = param_1;
  FUN_00418b80(&local_4, &stack0x00000004); // decompiler flattens this/out/key formals
  if (local_4 == *(int *)(param_1 + 0x588)) {
    return 0xffffffff;
  }
  return *(undefined4 *)(local_4 + 0x10);
}
```

Decompiler flattens `FUN_00418b80` args; **assembly is authoritative** for map-this = `char+0x584`, out node on stack, key = stack formal.

### 3.3 Live bytes (prefix)

```text
51 56 8b f1 8d 44 24 0c 50 8d 4c 24 08 51 8d 8e 84 05 00 00 e8 ...
... 3b 86 88 05 00 00 5e 75 07 83 c8 ff 59 c2 04 00 8b 40 10 59 c2 ...
```

| Immediate | Decode |
|---|---|
| `84 05 00 00` | map base **`+0x584`** |
| `88 05 00 00` | end sentinel **`+0x588`** |
| `c2 04 00` | **`RET 4`** |

---

## 4. Mission-path call site (Requirements)

Inside `CVOGCharacter_CheckMissionRequirements` @ `0x0054635e`…:

```text
0054635e  MOV  EAX, [ESI+0x104]    ; Discipline type
00546364  CMP  EAX, -1
00546368  JLE  skip_discipline
0054636a  MOV  EDI, [ESI+0x108]    ; DisciplineValue threshold
00546370  PUSH EAX                 ; typeId
00546371  MOV  ECX, EBP            ; character (Requirements stack0)
00546373  CALL 0x0052ada0
00546378  CMP  EAX, EDI
0054637a  JGE  pass
0054637c  ... return -1
```

| Claim | Conf |
|---|---|
| Gate only when `Discipline` (`+0x104`) ≥ 0 | **High** |
| Fail when `balance < DisciplineValue` (`+0x108`) | **High** (`CMP/JGE`) |
| Missing type (`-1`) fails any positive threshold | **High** (`-1 < needed` for needed>−1 typical) |

---

## 5. Map layout (High)

| Offset | Role | Evidence |
|--------|------|----------|
| char `+0x584` | ordered-map header (`this` for `FUN_00418b80`) | `LEA ECX,[ESI+0x584]` |
| char `+0x588` | end / not-found sentinel node ptr | `CMP EAX,[ESI+0x588]` |
| node `+0x10` | balance value (`int`) | `MOV EAX,[EAX+0x10]` |
| node key | at map-node field used by find (`puVar1[3]` in `FUN_00418b80`) | map helper decompile |

`FUN_00418b80` is a **sorted tree lower-bound/find** writing either matching node or header sentinel into `*out`.

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Function boundary @ `0x0052ada0` | **High** | Xrefs + bytes |
| `__thiscall(char*, typeId) → int` + `RET 4` | **High** | Asm + Requirements site |
| Map @ `+0x584`, end `+0x588`, value `node+0x10` | **High** | Body immediates |
| Missing → `-1` | **High** | `OR EAX,-1` |
| No stores in body | **High** | Query only |
| Discipline gate consumer | **High** | Parent dual + live call site |
| Shared with item-cost / tooltip paths | **High** (role); product symbol open | Many non-mission xrefs |
| English product method name | **Tentative / Open** | Role sealed as resource balance by type |
| Runtime sample balances | **Open** | Not captured |

---

## 7. Clean ≡ raw

| Stage | Match |
|---|---|
| Find via `FUN_00418b80` | **Yes** |
| Sentinel compare `+0x588` → `-1` | **Yes** |
| Return `node+0x10` | **Yes** |
| No invented clamps | **Yes** |
| Scaffold still labels system `unknown` | **Gap** — dual upgrades system to missions-progression + shared resource |

---

## 8. Open residuals (owned elsewhere or deferred)

1. Product / RTTI English for this method and the map type at `+0x584`.
2. Whether cash, discipline points, and mission Discipline share one map vs aliases of the same table (same helper → **shared access path High**; schema open).
3. Dual of `FUN_00418b80` itself (generic map find — not mission-owned).
4. Runtime / bit-exact.

---

## 9. Port contract (AutoCore)

```
// Client eligibility uses the same resource map as item costs:
int GetResourceBalanceByType(Character* c, int typeId) {
  node = MapFind(c->resourceMap@+0x584, typeId);
  if (node == c->resourceMapEnd@+0x588) return -1;
  return *(int*)(node + 0x10);
}

// Mission Requirements Discipline gate:
if (mission.Discipline >= 0) {
  if (GetResourceBalanceByType(char, mission.Discipline) < mission.DisciplineValue)
    return hard_fail; // -1
}
```
