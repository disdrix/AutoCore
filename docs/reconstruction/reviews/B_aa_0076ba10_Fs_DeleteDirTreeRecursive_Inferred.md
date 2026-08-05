# Review B (skeptical / adversarial): `aa_0076ba10` Fs_DeleteDirTreeRecursive_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076ba10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-A) |
| **Counterpart** | `reviews/A_aa_0076ba10_Fs_DeleteDirTreeRecursive_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Non-recursive path deletes files then rmdir | **Falsified** — flag==0 only `_rmdir`; no list/walk |
| 2 | `FUN_0076b080(param_2)` deletes using flag as path | **Falsified** — peer decompile uses `unaff_ESI` as path; flag is force/chmod gate |
| 3 | Join uses Windows `"\\"` | **Falsified** — `DAT_00a2eb5c` = `"/"` (`2f 00…`) |
| 4 | File-fail printf uses full path | **Falsified** — uses basename vector element; dir-fail uses full |
| 5 | Any child fail aborts and returns false immediately | **Falsified** — printf + continue; return is only final `_rmdir` |
| 6 | thiscall / ECX path | **Falsified** — bare `RET` after `ADD ESP,0x70` (cdecl) |
| 7 | Product name sealed | **Careful** — structural `_Inferred` only; plates prove delete FS family |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Recursive list/join/rmdir CF | **High** | Wrong FS purge |
| cdecl (path, byte flag) | **High** | ABI crash |
| ESI path into `FUN_0076b080` | **High** | Wrong unlink target |
| Fail-soft printf | **High** | Wrong error policy |
| `"/"` separator | **High** | Path join mismatch |
| Product plate | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Callers:
//   FUN_0076bc00: if is_dir(path) FUN_0076ba10(path,1); CreateDirectoryA
//   FUN_00985010 CompactPackFile @ 0x0098531f
//   FUN_007b75b0 @ 0x007b762e
//   self @ 0x0076bb3c
// Peer FUN_0076b080: force + ESI path; optional _chmod(0x180) then _unlink
// SEH LAB_009adcab; body 495 B; ADD ESP,0x70; RET
// Live decompile 2026-07-29 ≡ raw 2026-07-23 CF
// W33-C peers: list basenames 0076b3f0; is_dir 0076adc0
```

---

## 4. Surviving contract for AutoCore

```
// Port as recursive directory purge:
bool Fs_DeleteDirTreeRecursive(const char* path, bool recursive_force) {
  if (!recursive_force) return _rmdir(path) == 0;
  // list basenames only (0076b3f0); join with "/";
  // if is_dir: recurse; else force-unlink (chmod if force);
  // failures: log + continue; return final rmdir success.
}
// cdecl 2 args. Do NOT use "\\" join. Do NOT treat child fail as hard abort.
```

---

## 5. Verdict

Adversarial pass confirms A on cdecl ABI, recursive CF, fail-soft logging, and `"/" join`. Residual product/`FUN_00431ae0` layout → **accept-with-gaps**.
