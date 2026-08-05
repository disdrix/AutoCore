# Review A (reconstruction fidelity): `aa_00580a20` StatusFlag_GetDisplayName

| Field | Value |
|---|---|
| **Stable ID** | `aa_00580a20` |
| **VA** | `0x00580a20`–`0x00580ac0` |
| **Canonical name** | `StatusFlag_GetDisplayName` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (status flag → English name leaf) |
| **Counterpart** | `reviews/B_aa_00580a20_StatusFlag_GetDisplayName.md` |
| **System** | `skills-abilities` / status UI |
| **Verdict** | **accept** — ABI/CF/string table sealed; leaf complete |

**Tools:** Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + callers/xrefs. **No** `disassemble_bytes`. **No** Launcher. Own VA only.

---

## 1. Purpose

Leaf table that converts a status-flag **key** (power-of-two style int) into a static product English string for UI (cast-block toast suffixes and related paths).

```
StatusFlag_GetDisplayName(flagValue) -> const char*
  known power-of-two keys → product names (Stunned, Afraid, Weapons Disabled, ...)
  else → "in a world of hurt"
```

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | `decompile_function` `0x00580a20` ≡ scaffold raw |
| Live bytes | `read_memory` entry 160 B + epilogue `C3` @ `0x00580ac0` + jump table @ `0x00580ac4` |
| String pool | `read_memory` @ `0x009d44c8` cluster |
| Callers | `Client_CastBlockFeedback` `0x0093b7f0` (3); `FUN_00618c80` (11+) |
| Clean | `reconstructed-exact/StatusFlag_GetDisplayName.cpp` |
| Raw / annotated | `raw/aa_00580a20_StatusFlag_GetDisplayName{,.annotated}.md` |
| Function record | `functions/aa_00580a20_StatusFlag_GetDisplayName.md` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED / Confirmed**

| Fact | Evidence |
|---|---|
| Convention | Stack arg only — `mov eax,[esp+4]` |
| Return | `const char*` in EAX via `mov eax, imm32; ret` |
| Epilogue | plain `RET` (`C3`) — **not** `RET n` |
| Body | `0x00580a20`–`0x00580ac0` |
| Static callees | **none** |

```c
const char * StatusFlag_GetDisplayName(int flagValue);
```

### 3.2 Control flow — **SEALED**

Live decompile **≡** 2026-07-23 raw (no CF delta). Nested range ladder + switch for low band; exact-match ifs for mid/high; single default.

### 3.3 String table — **Confirmed**

| Key | String |
|---:|---|
| `0x01` | `GM Frozen` |
| `0x02` | `Stunned` |
| `0x04` | `Locked Down` |
| `0x08` | `Silenced` |
| `0x10` | `Weapons Disabled` |
| `0x20` | `GM Chat Banned` |
| `0x40` | `Afraid` |
| `0x80` | `Confused` |
| `0x200` | `Blind` |
| `0x1000` | `Slowed` |
| `0x2000` | `Immune to death` |
| `0x4000` | `Speeding` |
| `0x10000` | `Zombied` |
| default | `in a world of hurt` |

### 3.4 Role vs scaffold name — **SEALED**

Scaffold `Combat_Weapons_Disabled` is **wrong** as unit name: only one of thirteen named cases. Canonical `StatusFlag_GetDisplayName` matches caller use in `Client_CastBlockFeedback` (“Status name table”).

### 3.5 Caller key encoding — **High (context)**

Cast-block: status byte bit `8` → call with key **`2`** (Stunned); bit `0x80` → key `0x80`; bit `0x40` → key `0x40`. Bit→key mapping is **caller-owned**; this unit is pure key→string.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Stack single-arg + plain RET | **Confirmed** | `read_memory` |
| Full CF / string table | **Confirmed** | decompile ≡ raw ≡ pool |
| Leaf (no callees) | **Confirmed** | |
| Structural name | **Probable** | no RTTI; role High |
| Multi-bit OR never intentional | **Probable** | would hit default |

---

## 5. Gaps

1. Product/RTTI English for the C++ symbol (if any).
2. Inventory of dead mid-band keys.
3. Runtime toast golden for each known key.
4. Dual of `FUN_00618c80` (not OWN).

**Verdict:** **accept** — pure sealed leaf; clean ≡ raw CF; rename supersedes Weapons-Disabled scaffold.
