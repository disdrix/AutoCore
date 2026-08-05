# Review B (skeptical / adversarial): `aa_0076b080` Fs_UnlinkFile_ESI_ForceChmod_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076b080` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-S) |
| **Counterpart** | `reviews/A_aa_0076b080_Fs_UnlinkFile_ESI_ForceChmod_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Stack arg is the path string | **Falsified** — stack is force byte; path is **ESI** |
| 2 | Force always chmods | **Falsified** — only force + regular file + not writable |
| 3 | Bit15 is directory | **Falsified** — MSVC `_S_IFREG=0x8000`; dir helpers use other checks (`FUN_0076adc0`) |
| 4 | Returns `_chmod` status | **Falsified** — always returns `_unlink==0` |
| 5 | stdcall | **Falsified** — callers `ADD ESP,4`; callee `RET` |
| 6 | Recursive directory delete | **Falsified** — single path unlink only; recurse is `FUN_0076ba10` |
| 7 | Product assManager name | **Reject** — caller plate only; structural FS name |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI path + force flag | **High** | Wrong delete target / ABI |
| Mode bit semantics | **High** | chmod wrong files |
| Unlink return | **High** | Error policy |
| cdecl | **High** | Stack imbalance |
| Product English | **Low** | Naming only |
| Runtime | **Open** | Matrix |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Body 114 B full hex sealed; end 83c428c3
// Callers: 0076ba10 (W34-A peer), 0076bc00, 007b75b0
// 0076bb7d: LEA ESI,[path]; PUSH force; CALL; ADD ESP,4
// 0076bc5f / 007b765d: PUSH 1; CALL; ADD ESP,4 (ESI=path)
// CRT: stat import, _chmod 0x180, _unlink
// Live decompile ≡ raw scaffold + W37-S hex seal
```

---

## 4. Surviving contract for AutoCore

```
// Port as single-file force-unlink:
// path is REGISTER (ESI), force is stack char.
bool Fs_UnlinkFile_ForceChmod(const char* path, bool force) {
  if (force && is_regular(path) && !writable(path))
    _chmod(path, _S_IREAD|_S_IWRITE);
  return _unlink(path) == 0;
}
// Do NOT pass force as path. Do NOT treat as recursive rmdir.
// Pair with Fs_DeleteDirTreeRecursive (W34-A).
```

---

## 5. Verdict

Adversarial pass confirms A: ESI path, force chmod gate, unlink bool, cdecl. Product English residual only → **accept**.
