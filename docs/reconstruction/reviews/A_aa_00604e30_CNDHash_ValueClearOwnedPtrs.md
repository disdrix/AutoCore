# Review A (reconstruction fidelity): `aa_00604e30` CNDHash_ValueClearOwnedPtrs

| Field | Value |
|---|---|
| **Stable ID** | `aa_00604e30` |
| **VA** | `0x00604e30`–`0x00604e84` (**85 B** / `0x55`) |
| **Canonical name** | `CNDHash_ValueClearOwnedPtrs` (Ghidra `FUN_00604e30`; **Inferred**) |
| **Prior alias** | `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00604e30` (**reject** product id) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity (OWN-ONLY dual W26-P Path A) |
| **Counterpart** | `reviews/B_aa_00604e30_CNDHash_ValueClearOwnedPtrs.md` |
| **System** | container / CNDHash (medal family; nested value for stamp `009ce0a8`) |
| **Live tools** | `decompile_function`, `read_memory`, `analyze_function_complete` (xrefs/callees) |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** — closes reclaim residual “nested field matrix of FUN_00604e30” |

**Tools note:** No `disassemble_bytes`. No Launcher. No parent ledgers.

---

## 1. Purpose

Nested teardown of owned heap fields on a CNDHash **value** object (ECX = value*):

```text
for off in (+4, +8, +0xC, +0x10):
  p = *(void**)(value+off)
  if p != 0: operator_delete(p)   // cdecl; RETURNS
  *(void**)(value+off) = 0
// does not free value; does not touch value+0
```

**Callers:** reclaim `CNDHash_ReclaimAll_ValueOwning_009ce0a8` @ `0051bfe4`; scalar dtor `FUN_0051bd90` @ `0051bda3`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw 2026-07-23 |
| Live bytes | full body through `5F 5E C3` |
| Parent reclaim dual | W25-F `aa_0051bfb0` (nested thiscall confirmed) |
| Scalar dtor raw | `aa_0051bd90` stamps `009ce0a8`, same nested+delete |
| Raw / clean | `raw/aa_00604e30_*`, `reconstructed-exact/CNDHash_ValueClearOwnedPtrs.cpp`, `FUN_00604e30.cpp` |

---

## 3. Authoritative body (sealed CF)

```c
void __fastcall CNDHash_ValueClearOwnedPtrs(void *value)
{
  void *p;
  p = *(void **)((char *)value + 4);  if (p) operator_delete(p); *(void **)((char *)value + 4) = 0;
  p = *(void **)((char *)value + 8);  if (p) operator_delete(p); *(void **)((char *)value + 8) = 0;
  p = *(void **)((char *)value + 0xc); if (p) operator_delete(p); *(void **)((char *)value + 0xc) = 0;
  p = *(void **)((char *)value + 0x10); if (p) operator_delete(p); *(void **)((char *)value + 0x10) = 0;
}
```

---

## 4. Machine seal (`read_memory` @ `0x00604e30`)

| Claim | Evidence | Conf |
|---|---|---|
| thiscall ECX→ESI | `56 8B F1` | **High** |
| zero via EDI | `57 33 FF` … `89 7E xx` | **High** |
| slots +4/+8/+0xC/+0x10 | four `8B 46` / `89 7E` pairs | **High** |
| delete cdecl returns | `50 E8 .. 83 C4 04` ×4 | **High** |
| plain RET | `5F 5E C3` | **High** |
| does not free this | never push ESI to delete | **High** |
| body size 85 B | hex through RET; pad `CC` | **High** |

---

## 5. Gaps

- Product / PDB English for value type and four pointees.
- Runtime / bit-exact / differential.
- Full product layout of medal value beyond these four slots.

## 6. Verdict

**accept-with-gaps** — ABI, CF, callers, nested-owning role sealed High. Name inferred by role (not PDB).
