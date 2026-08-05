# Review B (skeptical / adversarial): `aa_00786280` Profiler_Zone_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00786280` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00786280_Profiler_Zone_Ctor.md` |
| **Verdict** | **accept-with-gaps** on CF; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Normal MSVC thiscall with **self in ECX** | ECX stored at `+8` as parent; self is stack0/`EDI`; root uses `xor ecx,ecx` | **Falsified** |
| 2 | `ret 4` single stack arg | Body `c2 08 00` = **ret 8** | **Falsified** |
| 3 | Constructs timer inline without heap | `operator_new(0x30)` + `FUN_00780730` | **Falsified** |
| 4 | Name is `std::string` in zone | Stores single dword pointer at `+0` | **Falsified** (map keys are strings elsewhere) |
| 5 | `"Hermann"` is this function’s plate | String only at EnsureThreadSlot call site | **Misleading** if claimed local |
| 6 | Always non-null timer | OOM branch sets `+4=0` | **Falsified** |
| 7 | Initializes `+0x0c` | No store between `+8` and `+0x10` | **Falsified** |
| 8 | Map fully usable without `+0x1c` object | Insert uses `zone+0x1c`; ctor focuses head at `+0x20` | **Gap** — empty comparator / proxy unsealed |
| 9 | Gameplay entity ctor | Profiler-only callers | **Falsified** |
| 10 | Bit-exact / runtime | Static dual | **Fail** if claimed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Parent-in-ECX ABI | **High** | Parent/self swap → tree corruption |
| ret 8 / two stack args | **High** | Stack imbalance |
| Timer ownership @+4 | **High** | Start/leave crash |
| Root vs child parent | **High** | Broken hierarchy |
| Full map STL layout | **Med** | Insert/lookup off-by-field |
| Stat field dictionary | **Med** | Wrong profiler UI mapping |

---

## 3. Cross-check

| Item | Result |
|---|---|
| Raw ≡ live decompile | **Yes** |
| EnsureThreadSlot parent NULL | `33 c9` before call @ create path |
| FindOrCreate pushes new+name | decompile `FUN_00786280(local_90[0], param_2)` with ECX=parent |
| Hermann string | `0x00a9adc4` |
| Timer ctor ESI | `8b f0 e8 … 00780730` in body |

**Attack on “self is ECX thiscall”:** **Falsified** by root `xor ecx,ecx` still constructing valid zone with parent null.

---

## 4. Surviving contract for AutoCore

```
// parent in ECX (may be null)
// push name; push preallocated 0x5c self; call; ret 8
// self->timer may be null if OOM
```

**Falsified port mistakes:**

- Treating ECX as the constructed zone.
- Assuming single stack arg / `ret 4`.
- Skipping timer ctor (divisor never set).
- Forcing non-null parent for root.
- Owning/freeing name pointer without evidence (looks borrowed).

---

## 5. Open questions

1. What lives at `+0x0c` after first enter/leave?  
2. Exact `std::map` / `_Tree` layout starting at `+0x1c`.  
3. Flag `+0x58` consumers.  
4. Whether timer OOM is ever hit in practice (no null-check in start path?).

**Verdict:** **accept-with-gaps** — ABI and construct order sealed; map/stat English residual only.
