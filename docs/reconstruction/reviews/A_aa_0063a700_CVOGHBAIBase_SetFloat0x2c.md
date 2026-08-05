# Review A (reconstruction fidelity): `aa_0063a700` CVOGHBAIBase_SetFloat0x2c

| Field | Value |
|---|---|
| **Stable ID** | `aa_0063a700` |
| **VA** | `0x0063a700` |
| **Canonical name** | `CVOGHBAIBase_SetFloat0x2c` |
| **Prior names** | `FUN_0063a700`, `Named_CalleeOf_CVOGHBAIBase_Default_ctor_0063a700` |
| **Review date** | `2026-07-29` (dual A/B — W19-P OWN) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0063a700_CVOGHBAIBase_SetFloat0x2c.md` |
| **System** | `hbai` |
| **Dual status** | **Present** (supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Leaf float setter** for HBAI objects:

```
*(float*)(this + 0x2c) = value;
```

Called from Turreted / Default constructors with **0.0f**, and installed as **virtual method** at vtbl offset **+0x20**.

**Calling convention:** MSVC `__thiscall` — object in `ECX`; one stack float; `ret 4`.

| Slot | Role | Evidence |
|------|------|----------|
| `this` (ECX) | HBAI object | both ctor sites `mov ecx, esi` |
| stack0 | `float value` | `movss xmm0, [esp+4]`; ctors `push 0` |
| field `+0x2c` | destination float | `movss [ecx+0x2c], xmm0` |

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0063a700_FUN_0063a700.md` (+ 2026-07-29 live) |
| Annotated | `docs/reconstruction/raw/aa_0063a700_FUN_0063a700.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAIBase_SetFloat0x2c.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0063a700.cpp` |
| Function record | `docs/reconstruction/functions/aa_0063a700_CVOGHBAIBase_SetFloat0x2c.md` |
| Live decompile | Ghidra `decompile_function` `0x0063a700` (2026-07-29) |
| Live bytes | `read_memory` `0x0063a700` length 32 |
| Xrefs | `get_function_xrefs` — 2 CALL + 5 DATA |
| Caller context | `read_memory` Turreted @ `0x00639840`, Default @ `0x0063c950` |
| Vtbl slot | `read_memory` `0x009e3ce0` → pointer `0x0063a700` |

**Not performed:** `disassemble_bytes`, Launcher, live process, product field naming beyond offset.

---

## 3. Control flow: clean ≡ raw ≡ live bytes

| Stage | Match |
|---|---|
| Load stack arg into xmm0 | **Yes** — `f3 0f 10 44 24 04` |
| Store to `[ecx+0x2c]` via movss | **Yes** — `f3 0f 11 41 2c` |
| `ret 4` | **Yes** — `c2 04 00` |
| No other memory / calls | **Yes** — leaf |
| Decompiler dword assign ≡ float bits | **Yes** (width); **type upgraded by bytes** |

### 3.1 Decompiler type noise — **SEALED as artifact**

Ghidra shows `undefined4` assign. Bytes are exclusively **SSE scalar float** moves. Treat field and argument as **float**.

---

## 4. Offsets / ABI

| Item | Value | Evidence |
|------|-------|----------|
| Field offset | `+0x2c` | `movss [ecx+0x2c]` |
| Stack cleanup | `ret 4` | bytes |
| Vtbl method offset | `+0x20` from Turreted base `0x009e3cc0` / Default `0x009e3d40` | DATA slots `0x009e3ce0` / `0x009e3d60` |

---

## 5. Callers

| Site | Function | Arg |
|------|----------|-----|
| `0x00639860` | `CVOGHBAIWalkingCreatureTurreted_ctor` | `0.0f` (`push 0` after `xorps` nearby) |
| `0x0063c966` | `CVOGHBAIBase_Default_ctor` | `0.0f` (`push 0`) |

Closes prior gaps in Turreted / Default ctor reviews that listed `FUN_0063a700` meaning as open.

---

## 6. Naming

| Claim | Confidence |
|---|---|
| Role = float setter at `+0x2c` | **High / Sealed** |
| Canonical `CVOGHBAIBase_SetFloat0x2c` | **Probable** (role-based; PDB unknown) |
| Product field name | **Open** — do not invent |

---

## 7. Gaps

1. Product / semantic name of `+0x2c` (what gameplay quantity).
2. Runtime virtual call sites via vtbl[+0x20] beyond ctor init.
3. Bit-exact / live process verification.

**Verdict:** **accept-with-gaps** — ABI, bytes, callers, and store sealed; field product name residual.
