# Review A (reconstruction fidelity): `aa_004c1800` ParticleFluidLiquidChild_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c1800` |
| **VA** | `0x004c1800`–`0x004c187d` inclusive (**126 B** / `0x7E`) |
| **Canonical name** | `ParticleFluidLiquidChild_Ctor_Inferred` |
| **Ghidra name** | `FUN_004c1800` |
| **Prior alias** | `Named_CalleeOf_*Drive_NDRiver_fx_004c1800` (**reject** as product id) |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction fidelity (OWN-ONLY dual W37-G Path A) |
| **Counterpart** | `reviews/B_aa_004c1800_ParticleFluidLiquidChild_Ctor_Inferred.md` |
| **System** | client / particle fluid phase / liquid child |
| **Live tools** | `batch_decompile`, `analyze_function_complete`, `get_function_by_address`, `read_memory` (full 126 B). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** — closes W34-O residual “nested ctor FUN_004c1800 free” |

**Tools note:** No Launcher. No parent ledgers.

---

## 1. Purpose

Ctor for the **0x40-byte** liquid child created by `ParticleFluidPhase_CreateLiquidChild_Inferred`:

```c
// __thiscall  RET 4  returns this*
void* ParticleFluidLiquidChild_Ctor_Inferred(void *self /*ECX*/, void *phase /*stack*/);
```

1. SEH frame `LAB_009a1aa2`.
2. `*self = phase`.
3. List at `+0x04` frame: sentinel = `StdList_AllocSentinel_0xC_Inferred()` → store `+0x08`; size `+0x0C = 0`.
4. Active byte `+0x10 = 0`; dword `+0x14 = 0`.
5. `FUN_004c17b0(self+0x18, self)` — host-link subobject (bytes; decompiler flattens).
6. Zero `+0x20`…`+0x3C` (8 dwords).
7. `DAT_00b03794 = self`; return `self`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ raw 2026-07-23 CF |
| Live bytes | full 126 B through `RET 4` + `CC` pad |
| Parent | `ParticleFluidPhase_CreateLiquidChild_Inferred` (`0x004c1960`, W34-O) — `new(0x40)` + this ctor |
| Sentinel | `StdList_AllocSentinel_0xC_Inferred` (`0x004933f0`, W32-P) |
| Host-link | `FUN_004c17b0` (unowned) — vtbl `009cb7a4` |
| Global | `DAT_00b03794` publish (phase host peer `DAT_00b03790`) |

---

## 3. ABI / body (bytes)

| Claim | Evidence | Conf |
|---|---|---|
| Body `0x004c1800`–`0x004c187d` (126 B) | `get_function_by_address` + hex length | **High** |
| `MOV ESI,ECX` thiscall | hex | **High** |
| Stack phase @ `[esp+0x14]` after frame | hex `8B 44 24 14` | **High** |
| `C2 04 00` RET 4 | hex epilog | **High** |
| Return this (`MOV EAX,ESI`) | hex | **High** |
| `FUN_004c17b0` on `+0x18` | `8D 4E 18` / `56` / `E8` | **High** (bytes win) |
| Sole CALL site | xref `004c1995` | **High** |

---

## 4. Naming

| Candidate | Decision |
|---|---|
| `ParticleFluidLiquidChild_Ctor_Inferred` | **Accept** — structural; parent CreateLiquidChild + 0x40 child + liquid init chain |
| `FUN_004c1800` | scaffold |
| Named_CalleeOf NDRiver | **Reject** product identity |

---

## 5. Gaps

- Product/PDB demangle for liquid child class / `DAT_00b03794`.
- Full semantic map of zeroed `+0x20..+0x3C` (activate path uses `+0x38` later).
- Nested ownership details of `FUN_004c17b0` list insert into phase host.
- Runtime / bit-exact / differential.

---

## 6. Confidence

| Claim | Level |
|---|---|
| CF dual A ≡ raw ≡ live | **Confirmed** |
| thiscall + RET 4 + return this | **Confirmed** |
| Size 0x40 / sole CreateLiquidChild caller | **Confirmed** |
| Sentinel + host-link + global publish | **High** |
| Product English | **Open** |

**Verdict:** **accept-with-gaps.**
