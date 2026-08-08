# Review A (reconstruction fidelity): `aa_00522710` Character_SumCommodityTfidRowCost (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00522710` |
| **VA** | `0x00522710` |
| **Canonical name** | `Character_SumCommodityTfidRowCost` (**INFERRED**) |
| **Ghidra symbol** | `FUN_00522710` |
| **Review date** | `2026-08-04` |
| **Agent** | WQ8R-J OWN-ONLY |
| **Counterpart** | `reviews/B_aa_00522710_Character_SumCommodityTfidRowCost_Inferred.md` |
| **System** | `inventory-transfer` |
| **Parent batch** | WQ-008 residual dual seal (commodity/inventory cost callees) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Sum commodity TFID-row slot cost** for Character cargo inventory:

```c
// __thiscall: ECX = Character*
// ret 8: unused_arg (dead), tfidRow[5]{lo,hi}
int Character_SumCommodityTfidRowCost(Character* ch, uint32_t unused, const uint32_t* row) {
  int accum = 1;
  InventoryGrid* grid = *(*(ch + 0x250) + 0x2B0);
  for (int i = 0; i < 5; ++i) {
    uint32_t lo = row[i*2], hi = row[i*2+1];
    if ((lo & hi) == 0xFFFFFFFFu) continue;
    void* item = InventoryGrid_FindItemByCoid(grid, lo, hi);
    if (!item) return accum;
    void* def = *(void**)((char*)item + 0xA8);
    if (*(int*)((char*)def + 0x38) != 0x1A) return accum; // Commodity
    uint8_t w = *(*(uint8_t**)((char*)def + 0x3C) + 0x4C8);
    accum += w + i;
  }
  return accum;
}
```

No place/stamp. Read-only cost probe.

---

## 2. Inspected artifacts

| Artifact | Evidence |
|---|---|
| Live decompile | `batch_decompile` / `analyze_function_complete` ≡ raw scaffold |
| Live bytes | `read_memory` 99 B body + `ret 8` @ `0x00522770` |
| Callee | `FUN_00571010` InventoryGrid_FindItemByCoid (dualed; COID +0x160/+0x164) |
| Type enum | `CloneBaseObjectType.Commodity = 26` (`src/.../ClonebaseObjectType.cs`) |
| Callers | `0x0052278f` in `FUN_00522780`; `0x005244fe` in `FUN_005244e0` |
| Clean | `reconstructed-exact/Character_SumCommodityTfidRowCost_Inferred.cpp` |

**Not performed:** `disassemble_bytes`, Launcher, runtime.

---

## 3. Control flow: bytes ≡ decompile (with ABI seals)

| Stage | Match |
|---|---|
| ECX → EBX this | **Yes** (`mov ebx, ecx`) |
| EDI = stack arg1 TFID row (`[esp+0x18]` after 4 pushes) | **Yes** |
| Stack arg0 never loaded | **Yes** — dead formal |
| accum=1, i=0 | **Yes** |
| Null: `(lo & hi) == -1` skip | **Yes** |
| ECX = `*(*(this+0x250)+0x2B0)` before FindByCoid | **Yes** — decompiler drops ECX setup |
| `call FUN_00571010` (push hi, lo; ret 8 callee) | **Yes** (rel → `0x00571010`) |
| null item → return accum | **Yes** |
| def+0x38 == 0x1A else return | **Yes** |
| accum += `*(uint8*)(*(def+0x3C)+0x4C8) + i` | **Yes** (`movzx` / `add eax,esi` / `add ebp,eax`) |
| i∈[0,4] then return accum in EAX; `ret 8` | **Yes** |

### Body

| Field | Value |
|---|---|
| Start | `0x00522710` |
| End exclusive | `0x00522773` |
| Size | **99 B** (`0x63`) |
| Pad | `CC` → next fn `FUN_00522780` @ `0x00522780` |

### Offsets

| Off | Role | Confidence |
|----:|------|------------|
| `ch+0x250` | mid object* (cargo host) | **High** CF |
| mid`+0x2B0` | InventoryGrid* cargo | **High** (matches invType1 pattern) |
| `item+0xA8` | clonebase def* | **High** |
| `def+0x38` | type id | **High** |
| `def+0x3C` | type subblob* | **High** pointer |
| sub`+0x4C8` | uint8 cost/weight term | **High** load; English **Open** |

---

## 4. Callers (context, not owned)

| Caller | Role |
|---|---|
| `FUN_00522780` | `used = this(tier, row)`; `max = FUN_00520340(tier)`; float score from free = max−used |
| `FUN_005244e0` | for row 0..4: if row TFID non-null, `sum += this(rowIndex, rowPtr)`; stride +40 B |

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Formula + early-outs | **High** |
| ABI thiscall + ret 8 + dead arg0 | **High** |
| Commodity type 0x1A | **High** |
| FindByCoid grid this setup | **High** |
| Product method English | **Open** |
| Subblob+0x4C8 product label | **Open** |
| Runtime | **Open** |

**Verdict:** **accept-with-gaps** — sealed worker cost leaf for commodity TFID rows; name Inferred.
