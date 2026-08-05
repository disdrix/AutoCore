# Review B (skeptical / adversarial): `aa_0071a9d0` AssPackObject_OpenFromPath_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071a9d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-X) |
| **Counterpart** | `reviews/A_aa_0071a9d0_AssPackObject_OpenFromPath_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Plain `void` / no formals (decompiler) | **Falsified** — EAX path, EDI pack, stack owner, **`RET 4`** |
| 2 | bit15 means directory | **Falsified** — MSVC `_S_IFREG` is 0x8000 (bit 15); `_S_IFDIR` is 0x4000 (bit 14) |
| 3 | Single file open always | **Falsified** — regular-file path dual-opens `EDI` and `EDI+0x14` |
| 4 | This **is** AssPackManager | **Falsified** — manager is stack/EBX; pack is EDI from `FUN_00719970` |
| 5 | Always returns −1 on empty file | **Falsified** — size vcall `== 0` returns **0** (success empty) |
| 6 | `"glm"` is a log string | **Falsified** — raw bytes `67 6c 6d 00` used as ESI ext token into path helper |
| 7 | Name is product demangle | **Careful** — `_Inferred` from sole assPackManager caller + structural open CF |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX/EDI/stack + RET 4 | **High** | Wrong call sequence from manager |
| Dual-open +0x14 on regular file | **High** | Missing second handle / TOC fail |
| Mode 1/3 vs 6 policy | **High** (bytes) | Wrong create vs open |
| CreateFile flag mapping | **Medium** | Depends on unowned open helper |
| Parse `FUN_0071a4a0` | **Low–Medium** | Pack contents wrong if mis-ported |
| Product class English | **Low** | Naming only |

---

## 3. Cross-check against raw + bytes + xrefs

- Full 277 B hex ends `… 5E 81 C4 30 01 00 00 C2 04 00`.
- Sole xref `0x00984f66`: `MOV EDI,EAX` (pack), `PUSH EBX` (manager), `MOV EAX,ESI` (path), `CALL 0071a9d0`, `TEST EAX` / `JGE` success.
- Caller plate strings seal subsystem: Opening/FAILED/SUCCESS pack file (`assPackManager.cpp`).
- Decompiler `unaff_EDI` / `in_EAX` are **register formals**, not true unaffiliated junk — sealed by sole caller.

---

## 4. Surviving contract for AutoCore

```
// Port as pack open with register ABI:
int AssPackObject_OpenFromPath(const char* path /*EAX*/,
                               AssPackObject* pack /*EDI*/,
                               AssPackManager* owner /*stack*/);
// strdup path @ +0x28; glm path normalize; mode from +0x40;
// if regular file: open pack and pack+0x14 with mode 1|3;
// else open pack mode 6; then size/seek/footer/parse.
// Return 0 empty success; <0 fail; else parse status.
```

---

## 5. Verdict

Adversarial pass confirms A on register ABI, glm path, dual-open, mode policy, footer handoff. Residual unowned parse + product English → **accept-with-gaps** (same as A).
