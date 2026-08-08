# Review A (reconstruction fidelity): `aa_005244e0` Character_SumCommodityTfidFiveRowCosts (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_005244e0` |
| **VA** | `0x005244e0`–`0x00524518` inclusive (**57 B** / `0x39`) |
| **Canonical name** | `Character_SumCommodityTfidFiveRowCosts` (**INFERRED**) |
| **Ghidra symbol** | `FUN_005244e0` |
| **Review date** | `2026-08-05` |
| **Agent** | R11-001 OWN-ONLY |
| **Counterpart** | `reviews/B_aa_005244e0_Character_SumCommodityTfidFiveRowCosts_Inferred.md` |
| **System** | `inventory-transfer` |
| **Parent batch** | R11 residual dual; parent `0x00522710` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Sum commodity TFID-row slot costs** across a fixed **5-row** table on Character:

```c
// __thiscall: ECX = Character*
// ret 4: table[5 rows × 5 TFID pairs]
int Character_SumCommodityTfidFiveRowCosts(Character* ch, const uint32_t* table) {
  int sum = 0;
  for (int i = 0; i < 5; ++i) {
    const uint32_t* row = table + i * 10;
    if ((row[0] & row[1]) == 0xFFFFFFFFu) continue; // null head
    sum += Character_SumCommodityTfidRowCost(ch, i, row); // FUN_00522710
  }
  return sum;
}
```

Read-only multi-row cost probe. No place/stamp/mutation.

---

## 2. Inspected artifacts

| Artifact | Evidence |
|---|---|
| Live decompile | ≡ original raw scaffold CF |
| Live bytes | `read_memory` 57 B body + `ret 4` @ `0x00524516`; pad `CC` → `0x00524520` |
| Full listing | `disassemble_function` — ECX→EBP this; EDI table; EBX sum; ESI index; stride `ADD EDI,0x28` |
| Callee | `FUN_00522710` `Character_SumCommodityTfidRowCost_Inferred` (dualed WQ-008); rel call sealed |
| Sibling | dualed `Character_CalcCommodityTierFreeScore_Inferred` `0x00522780` (one-tier free score; not this) |
| Callers | **none** (`get_function_callers` / `get_xrefs_to` / `get_bulk_xrefs` empty) |
| Clean | `reconstructed-exact/Character_SumCommodityTfidFiveRowCosts_Inferred.cpp` |

**Not performed:** `disassemble_bytes`, Launcher, runtime.

---

## 3. Control flow: bytes ≡ decompile (with ABI seals)

| Stage | Match |
|---|---|
| ECX → EBP this | **Yes** (`mov ebp, ecx`) — decompiler omits |
| EDI = stack table* (`[esp+0x14]` after 4 pushes) | **Yes** |
| sum=0 (EBX), i=0 (ESI) | **Yes** |
| Null head: `(lo & hi) == -1` skip | **Yes** (`and` / `cmp -1` / `jz`) |
| Push row*, push i; ECX=this; `call FUN_00522710` | **Yes** |
| `sum += EAX` | **Yes** (`add ebx, eax`) |
| `i++`; `row += 0x28`; loop while `i < 5` | **Yes** |
| `EAX = sum`; **`ret 4`** | **Yes** (`mov eax,ebx` / `C2 04 00`) |

### Body

| Field | Value |
|---|---|
| Start | `0x005244e0` |
| End inclusive | `0x00524518` |
| Size | **57 B** (`0x39`) |
| Pad | `CC` → next fn `FUN_00524520` @ `0x00524520` |

### Offsets / layout

| Item | Role | Confidence |
|---|---|---|
| table row stride `0x28` | 5×`{lo,hi}` TFID pairs | **High** CF |
| 5 outer iterations | fixed table height | **High** |
| Head null via AND | same as dualed per-row worker | **High** |
| Callee stack arg0 = rowIndex | **dead** inside callee (dual sealed) | **High** (parent dual) |

---

## 4. Callers (context, not owned)

| Caller | Role |
|---|---|
| *(none recovered)* | Possible indirect / dead / Ghidra xref gap |

Partition parent `0x00522710` is the **callee**, not a structural caller of this unit.

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Formula + null-head skip + stride | **High** |
| ABI thiscall + ret 4 | **High** |
| Callee identity + wiring | **High** |
| Product method English | **Open** |
| Live callers | **Open** |
| Tier-row product mapping | **Open** |
| Runtime | **Open** |

**Verdict:** **accept-with-gaps** — sealed multi-row commodity cost sum wrapper; name Inferred; callers residual.
