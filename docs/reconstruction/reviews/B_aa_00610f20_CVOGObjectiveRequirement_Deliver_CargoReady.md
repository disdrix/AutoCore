# Review B: `aa_00610f20` Deliver CargoReady

| Field | Value |
|---|---|
| **Review date** | `2026-07-29` (dual residual strengthen) |
| **Verdict** | **accept-with-gaps** |
| **Stable ID** | `aa_00610f20` |
| **Address** | `0x00610f20` |

## Skeptical re-check

| Claim from A / residual | Challenge | Outcome |
|-------------------------|-----------|---------|
| `+0x23==0` bypasses qty | Could “0 mean enforce”? | **Reject challenge.** Asm: short count → `CMP [ESI+0x23],0` → **`JE ready`**. Zero → ready. Non-zero falls to fail. **High** |
| Default enforce | Ctor noise? | Ctor stores **1** to `+0x20..+0x23` with same `AL=1`. Sibling OnInventoryEvent shares OR form. **High** |
| Authored only via CBIDItem −1 | Hidden XML tag? | GetFlags dumps `+0x20/+0x21/+0x22` with known tags; **no** `+0x23` dump string. Unserialize only writes `+0x23` on **`EAX==-1`** after CBIDItem parse. **High** |
| “CargoReady” name | Invented symbol? | Role = pure bool readiness for deliver cargo; RTTI class is Deliver; method still **`_Inferred`**. **Probable** name only — do not invent PDB. |
| Decomp `param_1+0x14 <= count` | Signed vs unsigned? | Asm `CMP EAX,[need]; JGE` — **signed** compare, same as decomp `need <= count`. **High** |
| Clean vehicle null-check | Present in raw? | **No.** Raw loads `*(char+0x250)` without TEST; only grid null-checked. Clean is defensive. **High** (raw truth) |
| Server `RequireItemToComplete` | Same polarity? | Server assigns `== -1 → true`; client `== -1 → +0x23=0`. **Inverted.** Do not treat server field as sealed client mirror. |

## Confidence board

| Area | Level |
|------|-------|
| Control flow / predicate | **High** |
| `+0x23` polarity + authorship | **High** |
| ABI RET 8 / virtual slot | **High** |
| Method English name | **Probable** (`_Inferred`) |
| matchKey domain label | **Probable** |
| Runtime / bit-exact | **Open** |

**Verdict:** **accept-with-gaps**. Naming remains **Probable**; CF and **`+0x23` polarity** **High**. No invent of original symbol. Polarity matches sibling OnInventoryEvent; authorship sealed as CBIDItem-derived.
