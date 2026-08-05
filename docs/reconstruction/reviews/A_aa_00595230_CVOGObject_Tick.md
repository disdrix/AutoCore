# Review A (reconstruction fidelity): `aa_00595230` CVOGObject_Tick

| Field | Value |
|---|---|
| **Stable ID** | `aa_00595230` |
| **VA** | `0x00595230`–`0x005960fc` (3788 B / `0xECC`) |
| **Canonical name** | `CVOGObject_Tick` (structural; product/PDB open) |
| **Ghidra name** | `FUN_00595230` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W23-H) |
| **Counterpart** | `reviews/B_aa_00595230_CVOGObject_Tick.md` |
| **System** | client object / per-frame tick |
| **Verdict** | **accept-with-gaps** — phase CF + ABI + gates sealed; nested pose math residual |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + callers/callees + `get_function_by_address`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Per-frame **tick** for a client world object (`this`):

- Reaction/phase timer and optional multi-hit flush.
- Lifetime/fade timer.
- Parent / gfx pose update (`"Update Parent Pos"`).
- Deferred Just-created finalize via `CVOGObject_JustCreatedInit(mode=0)`.
- Velocity cache + gfx writeback.

Evidence: profiler strings; sole caller SpecialFX walk; mode-0 JustCreatedInit linkage dualed in W22-H.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | full ~400 lines @ `0x00595230` |
| Entry/exit bytes | `read_memory` @ `0x00595230`, `0x005960d0` |
| Constants | `DAT_00aaa638`, `DAT_009d51d8`, `0x00a10e74` |
| Callers | `FUN_004b8ed0` only |
| Related dual | `CVOGObject_JustCreatedInit` (`aa_005911b0`) |
| Raw / annotated / clean | W23-H updated |

**Not performed:** Launcher, runtime golden, bit-exact, line dual of every quat helper.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body range `00595230`–`005960fc` | **Confirmed** | `get_function_by_address` |
| `__thiscall` + **`ret 8`** | **Confirmed** | epilogue `C2 08 00` |
| Two stack args (dt + ctx) | **Confirmed** | ret 8; decomp formals |
| `"Time etc.."` / `"Update Parent Pos"` phases | **Confirmed** | strings |
| JustCreatedInit mode 0 abort on 0 | **Confirmed** | decomp + W22-H |
| `DAT_00aaa638` = 1/65535 | **Confirmed** | `read_memory` |
| `DAT_009d51d8` = 1e-6 | **Confirmed** | `read_memory` |
| Quat factor 2.0 at `0x00a10e74` | **Confirmed** | `read_memory` + prior duals |
| Full soft-flag dictionary | **Tentative** | partial from gates |
| Every pose formula bit-exact | **Open** | large body |
| Product class method name | **Inferred** | CVOG object family |
| Runtime / differential | **Open** | |

---

## 4. Control flow checklist (phase)

| Stage | Match |
|---|---|
| SEH + counters | Yes |
| Optional multi `FUN_00634c50` | Yes |
| Phase timer + reaction advance | Yes |
| Lifetime timer early out | Yes |
| Gate not-created / just-created | Yes |
| Update Parent Pos pose paths | Yes |
| Zero-geo warning | Yes |
| JustCreatedInit(0) | Yes |
| Gfx velocity / integrate | Yes |
| Clear just-created bit | Yes |
| Epilogue ret 8 | Yes |

---

## 5. Callers

| Caller | Site | Notes |
|---|---|---|
| `FUN_004b8ed0` | `0x004b909d` | ECX = child object; stack `*param_2` + clock float (`FUN_0079a110` → global+0x238) |

---

## 6. Gaps

1. Retail / PDB symbol.
2. Exhaustive soft-flag dictionary `@+0x90c..+0x911`.
3. Product meaning of second stack formal beyond forward to `FUN_005942d0`.
4. Line-level dual of remaining nested pose helpers.
5. Runtime golden.

**Verdict:** **accept-with-gaps** — sealed as object tick with ABI, phase map, JustCreated linkage; residual nested math / flags.
