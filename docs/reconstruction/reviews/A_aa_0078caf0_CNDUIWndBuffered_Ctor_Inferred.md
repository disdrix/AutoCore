# Review A (reconstruction fidelity): `aa_0078caf0` CNDUIWndBuffered_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0078caf0` |
| **VA** | `0x0078caf0`–`0x0078cecb` exclusive (**987 B** / `0x3DB`) |
| **Canonical name** | `CNDUIWndBuffered_Ctor_Inferred` |
| **Prior scaffold** | `FUN_0078caf0` |
| **Review date** | `2026-07-29` (W34-T dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0078caf0_CNDUIWndBuffered_Ctor_Inferred.md` |
| **System** | client / ND UI buffered window |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `get_function_by_address` + xrefs + `read_memory_bytes` + RTTI COL. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Complete constructor for **`CNDUIWndBuffered`**: base `CNDUIWindow` ctor, install own vtbl, field bank, nested HostBase (`0x80` @ `+0x2A8`) + ensure aux with flag **1**.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | ≡ 2026-07-23 raw CF |
| Bytes | SEH; `ret 12` @ end; call-site `push` triples |
| RTTI | vtbl `00a99f74` COL `00ab8280` TD `00afe4d0` → **`.?AVCNDUIWndBuffered@@`** |
| Size | `operator_new(0x4FC)` at 3 sites (`68 FC 04 00 00`) |
| Callers | Portrait / Vehicle / Particles subclass ctors + 3 `new(0x4FC)` sites |
| Related | dtor `0078ca80`; HostBase W32-O/Q |
| Raw / clean | `aa_0078caf0_*`, `CNDUIWndBuffered_Ctor_Inferred.cpp` |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 987 B / ret 12 / return this | **Confirmed** | bytes |
| Class CNDUIWndBuffered | **Confirmed** | COL chain |
| Size 0x4FC | **Confirmed** | new immediates |
| Base CNDUIWindow via 007b5dd0 | **Confirmed** | base vtbl RTTI |
| HostBase @ +0x2A8 | **Confirmed** | W32-O/Q + bytes |
| Field-bank product English | **Open** | literals sealed |
| arg1/arg2 product meaning | **Open** | 0/1 observed |
| Runtime / differential | **Open** | |

---

## 4. Control flow: clean ≡ raw ≡ live

```c
CNDUIWindow_Ctor(this, arg1)
*this = CNDUIWndBuffered_vtbl
field bank; +0x488 = arg2
host = new(0x80) ? HostBase_DefaultCtor : null
+0x2A8 = host; EnsureAux(host, 1)
return this
```

| Stage | Match |
|---|---|
| Base then vtbl then fields then HostBase | Yes |
| ret 12 | Yes |

---

## 5. Gaps / open

1. Product English for full field bank / color rows.
2. Formal `arg1`/`arg2` meaning beyond observed constants.
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — sealed CF, ABI, RTTI, size, HostBase hookup, subclass callers; field-bank residual.
