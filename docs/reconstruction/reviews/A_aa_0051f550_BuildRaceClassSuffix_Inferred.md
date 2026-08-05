# Review A (reconstruction fidelity): `aa_0051f550` BuildRaceClassSuffix_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051f550` |
| **VA** | `0x0051f550` |
| **Canonical name** | `BuildRaceClassSuffix_Inferred` (Ghidra `FUN_0051f550`) |
| **Ghidra name** | `FUN_0051f550` |
| **Prior alias** | `Named_CalleeOf_Drive_Vehicle_0051f550` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_0051f550_BuildRaceClassSuffix_Inferred.md` |
| **System** | UI / garage resource path suffix (race × class) |
| **Live tools** | `batch_decompile`, `read_memory` string literals, garage caller |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

Build a **short ASCII suffix string** into global buffer `DAT_00b04600` from two small enums (race, class/chassis), then return `&DAT_00b04600`:

```c
// __cdecl-ish (two stack ints)
char* BuildRaceClassSuffix_Inferred(int raceIndex, int classIndex);
```

### Algorithm

1. `DAT_00b04600 = 0` — clear buffer (empty C string).
2. If `raceIndex` ∈ {0,1,2}: append 3-byte token from rodata (`"_h\0"`, `"_m\0"`, `"_b\0"`).
3. `switch (classIndex)` 0..3: append (`"_c\0"`, `"_e\0"`, `"_o\0"`, `"_r\0"`).
4. Return `&DAT_00b04600` (even if class out of range — may be race-only or empty).

### String table (`read_memory` @ `0x009ceee0`, 28 bytes)

| Addr | Bytes | Token | Role |
|---|---|---|---|
| `009ceee0` | `5f 72 00` | `_r` | class 3 |
| `009ceee4` | `5f 6f 00` | `_o` | class 2 |
| `009ceee8` | `5f 65 00` | `_e` | class 1 |
| `009ceeec` | `5f 63 00` | `_c` | class 0 |
| `009ceef0` | `5f 68 00` | `_h` | race 0 Human |
| `009ceef4` | `5f 6d 00` | `_m` | race 1 Mutant |
| `009ceef8` | `5f 62 00` | `_b` | race 2 Biomech |

Nearby rodata also holds `HUM` / `MUT` / `BIO` labels — race naming seal.

### Callers

| Caller | Args |
|---|---|
| `FUN_00521080` | `race=def+0x532`, `class=def+0x531` from object dual-base def |
| Garage UI `FUN_008801b0` | Builds `i_d_v_2d_icon_race` + suffix from local vehicle race; sometimes `class = -1` → race-only (`_h` / `_m` / `_b`) |

Example outputs: `"_h_c"`, `"_m_e"`, `"_b"` (race only when class invalid).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile` @ `0x0051f550` ≡ raw |
| Tokens | `read_memory` `0x009ceee0` length 48 |
| Def bytes | `FUN_00521080` (`+0x532` / `+0x531`) |
| Garage path | `FUN_008801b0` + string `i_d_v_2d_icon_race` |
| Raw / clean | `raw/aa_0051f550_*`, `reconstructed-exact/FUN_0051f550.cpp` |

---

## 3. Confidence

| Claim | Level |
|---|---|
| CF dual A≡B ≡ raw ≡ live | **Confirmed** |
| Tokens `_h/_m/_b` and `_c/_e/_o/_r` | **Confirmed** (`read_memory`) |
| Buffer `DAT_00b04600` global, not thread-local | **Confirmed** |
| Race 0/1/2 = H/M/B | **High** (kit strings Shield/HEART/Hazard + HUM/MUT/BIO) |
| Class 0..3 = c/e/o/r product names | **Probable** (letter only; English open) |
| Re-entrant / concurrent use safe | **Open** (static buffer) |

**Verdict:** **accept-with-gaps.**
