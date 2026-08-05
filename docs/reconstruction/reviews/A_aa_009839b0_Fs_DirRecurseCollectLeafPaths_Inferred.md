# Review A (reconstruction fidelity): `aa_009839b0` Fs_DirRecurseCollectLeafPaths_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009839b0` |
| **VA** | `0x009839b0`–`0x00983b53` (**420 B**) |
| **Canonical name** | `Fs_DirRecurseCollectLeafPaths_Inferred` |
| **Ghidra name** | `FUN_009839b0` |
| **Review date** | `2026-07-29` (W32-D dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-D) |
| **Counterpart** | `reviews/B_aa_009839b0_Fs_DirRecurseCollectLeafPaths_Inferred.md` |
| **System** | filesystem / path enumeration |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (body bounds + separator) + xrefs/callers |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Recursive directory leaf-path collector:

1. SEH `LAB_009ad54e`; large frame.
2. If `!FUN_0076adc0(path)` (not a directory) → **return `-1`**.
3. `FUN_0076b3f0(path, &listing)` fill entry vector (string stride `0x1c`).
4. For each entry: `full = path + "/" + entry` (`DAT_00a2eb5c` = `"/"`).
5. If leaf (`!is_dir(full)`): **thiscall push** onto **`param_2`** via `FUN_004301f0`.
6. If dir: **recurse** `FUN_009839b0(full, param_2)`.
7. Destroy listing; **return `0`**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_009839b0_FUN_009839b0.md` (+ W32-D append) |
| Annotated | `docs/reconstruction/raw/aa_009839b0_FUN_009839b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Fs_DirRecurseCollectLeafPaths_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_009839b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_009839b0_FUN_009839b0.md` |
| Named record | `docs/reconstruction/functions/aa_009839b0_Fs_DirRecurseCollectLeafPaths_Inferred.md` |
| Live | decompile ≡ scaffold CF; body 420 B; callers `00984340` / `00984c70` / self |
| Bytes win | leaf `MOV ECX,[esp+0xA4]; PUSH path; CALL FUN_004301f0` |
| Separator | `read_memory 00a2eb5c` → `2f 00 00 00` (`"/"`) |

---

## 3. Signature (sealed)

```c
// cdecl 2 formals; bare RET; EAX = 0 or 0xFFFFFFFF
int Fs_DirRecurseCollectLeafPaths_Inferred(const char* path, void* out_string_vec /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| path | Stack `[esp+4]` after SEH / `param_1` | **High** |
| out_vec | Stack `[esp+8]` / ECX for leaf push | **High** (bytes) |
| return | `XOR EAX,EAX` / `OR EAX,-1` | **High** |
| cleanup | bare `RET` (callers `ADD ESP,8`) | **High** |
| thiscall self | **No** | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if !is_dir(path): return -1
listing = list_dir(path)
for entry in listing:
  full = path + "/" + entry
  if !is_dir(full): push(out, full)
  else: recurse(full, out)
destroy(listing)
return 0
```

| Stage | Match | Conf |
|---|---|---|
| is_dir gate | **Yes** | **High** |
| list + stride 0x1c | **Yes** | **High** |
| join with `/` | **Yes** | **High** |
| leaf push to param_2 | **Yes** (bytes) | **High** |
| recurse | **Yes** | **High** |
| Product English | shape only | **Inferred** |

---

## 5. Gaps / open

1. Product plates for callers `FUN_00984340` / `FUN_00984c70` / `FUN_00984910`.
2. Exact listing-vector destroy ABI of `FUN_00431ae0` (unowned).
3. Whether empty directories return 0 with empty out (yes by CF; runtime open).
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
