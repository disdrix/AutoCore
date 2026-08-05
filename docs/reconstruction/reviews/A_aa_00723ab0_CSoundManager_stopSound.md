# Review A (reconstruction fidelity): `aa_00723ab0` CSoundManager::_stopSound

| Field | Value |
|---|---|
| **Stable ID** | `aa_00723ab0` |
| **VA** | `0x00723ab0` |
| **Body span** | `00723ab0` – `00723b14` |
| **Canonical name** | `CSoundManager::_stopSound` |
| **Ghidra symbol** | `FUN_00723ab0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra decompile + `read_memory` of body) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw-asm ≡ live) |
| **Counterpart** | `reviews/B_aa_00723ab0_CSoundManager_stopSound.md` |
| **System** | client audio / `CSoundManager` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**`CSoundManager::_stopSound`**: stop **one** sound slot by **index**.

1. **Index** arrives in **EAX** (not a stack arg).
2. **Manager `this`** arrives in **ECX**.
3. Reject if `index >= 0x30` or table entry at **`this+0x31c + index*4`** is null → **AL=0**.
4. If `slot+0x38 != 0` **or** `slot+0x3a != 0` → log product error string and **AL=0**.
5. Else: `FUN_007227e0(0.0f)` → store ST0 to **`slot+0x1b0`**, set **`+0x38=1`**, clear **`+0x3a=0`**, **AL=1**.

Used by `CSoundManager_StopMatchingSounds` (`FUN_00723b20`) and other stop paths that already resolved a slot index.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00723ab0_FUN_00723ab0.md` |
| Annotated | `docs/reconstruction/raw/aa_00723ab0_FUN_00723ab0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00723ab0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00723ab0_FUN_00723ab0.md` |

**This pass (live, OWN VA only):**

- Ghidra MCP `decompile_function` @ `0x00723ab0` — same plate as 2026-07-23 scaffold; **extras** (`uVar2` packing, `extraout_ECX`) rejected via body bytes.
- Ghidra MCP `read_memory` @ `0x00723ab0` length 128 — body ends `32 C0 C3` at `0x00723b14`; callees resolve to `FUN_007227e0`, `FUN_007a4480`; format string @ `0x00aa91d0`.
- Ghidra MCP `read_memory` @ `0x00aaa5d8` — `f32 -10000.0` (return of `FUN_007227e0` when arg ≤ 0).
- Ghidra MCP `decompile_function` @ `0x007227e0` — residual callee (not dual-owned); documents the `-10000.0` path only.
- **Not performed:** Launcher, runtime golden, bit-exact binary diff; **no ownership** of `0x007227e0` / `0x007a4480`.

---

## 3. Calling convention (assembly-sealed on OWN body)

| Slot | Role | Evidence |
|---|---|---|
| **EAX** | `uint index` (slot) | entry `cmp eax, 0x30` / scaled index into table |
| **ECX** | `CSoundManager *this` | `[ecx+eax*4+0x31c]` table base |
| **Stack** | none | plain `ret` |
| **Return** | **AL** bool | success `mov al,1; ret`; fail `xor al,al; ret` |

Ghidra `__fastcall FUN_00723ab0(int param_1)` with `in_EAX` index is **behaviorally correct**. Ports must load index into EAX.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span `00723ab0`–`00723b14`, plain `ret` | **High** | `read_memory` |
| Index EAX; this ECX | **High** | Own body |
| Table base `this+0x31c`, max index **0x30** (48) | **High** | `cmp eax,30h` / `jae` |
| Gate: both `+0x38` and `+0x3a` must be 0 | **High** | dual `cmp byte` / `jnz` |
| Success: `+0x38=1`, `+0x3a=0` | **High** | stores |
| `fstp [edx+0x1b0]` after `FUN_007227e0(0)` | **High** | `D9 9A B0 01 00 00` |
| Envelope value = **−10000.0f** for arg 0 | **High** | callee decomp + `DAT_00aaa5d8` |
| Product name `_stopSound` | **High** | string @ `0x00aa91d0` |
| Flag meanings from log text | **High** | “already stopped” / “flagged to start playing” |
| Ghidra `uVar2` / `extraout_*` packing | **Rejected** | not present in body bytes |
| Clean ≡ assembly-faithful CF | **High** | 2026-07-29 clean rewrites decompiler extras |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 5. Control flow checklist (clean ≡ annotated-asm ≡ live)

| Stage | Match |
|---|---|
| `index >= 0x30` → AL=0 | **Yes** |
| null `table[index]` → AL=0 | **Yes** |
| either flag non-zero → log + AL=0 | **Yes** |
| both flags zero → float store + mark stopped + AL=1 | **Yes** |
| Log format + flag order (`+0x38` then `+0x3a` as `%d,%d`) | **Yes** (`push +0x3a; push +0x38` → varargs first=`+0x38`) |
| No invent free / no table erase | **Yes** — mark only |

```text
_stopSound(this ECX, index EAX):
  if index >= 48 or table[index] == null: return 0
  inst = table[index]
  if inst.stopped(+0x38) or inst.startPlay(+0x3a):
    log(... stopped(%d)=+0x38, start(%d)=+0x3a); return 0
  inst.envelope(+0x1b0) = fadeHelper(0)   // -10000.0f
  inst.stopped = 1
  inst.startPlay = 0
  return 1
```

---

## 6. Gaps

1. **Product name of `slot+0x1b0`** (fade time vs gain vs sentinel only).
2. **`FUN_007227e0` full curve** not dual-owned — only the arg-`0` → `−10000.0f` path is used here.
3. Whether callers read **full EAX** vs **AL** only after return (success path briefly loads instance into EAX then `mov al,1`).
4. Runtime / differential verification **Open**.

**Verdict:** **accept-with-gaps** — CF and ABI sealed High for AutoCore audio stop; residual field naming on `+0x1b0` and fade helper body.
