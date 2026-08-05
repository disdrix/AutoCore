# Review B (skeptical / adversarial): `aa_009839b0` Fs_DirRecurseCollectLeafPaths_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009839b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-D) |
| **Counterpart** | `reviews/A_aa_009839b0_Fs_DirRecurseCollectLeafPaths_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `param_2` is unused / dead | **Falsified** — bytes load ECX from stack for leaf `FUN_004301f0` thiscall; callers pass listing sink (`FUN_00984c70` local_38) |
| 2 | Function is a placement ctor near `00983940` | **Falsified** — recursive walker; bare `RET`; returns 0/-1; no object install |
| 3 | ECX-thiscall on this unit | **Falsified** — cdecl 2 stack formals; callers `ADD ESP,8` |
| 4 | Processes / loads file contents | **Falsified** — only pushes path strings; content work is caller-side (`FUN_00984910`) |
| 5 | Separator is backslash | **Falsified** — `DAT_00a2eb5c` = `"/"` (`2f 00 00 00`); backslash appears only in related `FUN_00984340` / is_dir trim paths |
| 6 | Decompiler `FUN_004301f0(local_7c)` means push onto local_7c as vector | **Misleading** — local_7c is the **path string**; vector is ECX=`param_2` |
| 7 | Name claims PDB product | **Careful** — `_Inferred` structural only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| cdecl + return 0/-1 | **High** | Wrong ABI in port |
| is_dir gate + recurse | **High** | Wrong control flow |
| out-vector leaf push | **High** | Silent empty results |
| Separator `/` | **High** | Wrong path join |
| Product plate | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// FUN_00984c70:
//   listing = {}
//   rc = FUN_009839b0(path, &listing)
//   if rc >= 0: for each string in listing → FUN_00984910(...)
//   FUN_00431ae0()

// FUN_00984340 (dir + recurse flag):
//   FUN_009839b0(param_2, local_19c)
```

Live decompile 2026-07-29 ≡ scaffold 2026-07-23 CF. Body end `C3` @ `0x00983b53` (420 B). Self-xref at `0x00983ada` seals recursion.

---

## 4. Surviving contract for AutoCore

```
// Port as free function (cdecl), not method:
int DirRecurseCollectLeafPaths(const char* path, StringVector* out) {
  if (!IsDirectory(path)) return -1;
  StringVector entries = ListDirectory(path);
  for (entry : entries) {
    string full = path + "/" + entry;
    if (!IsDirectory(full)) out->push_back(full);
    else DirRecurseCollectLeafPaths(full.c_str(), out);
  }
  return 0;
}
// Preserve "/" separator. Do not invent product caller English.
// Pair with path-expand helpers 00984340 / 00984c70 when those duals land.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/separator/out-vector (bytes win). Residual product plates for callers + unowned helpers → **accept-with-gaps**.
