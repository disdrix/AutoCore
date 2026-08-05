# Review B (skeptical / adversarial): `aa_00985010` AssPackManager_CompactPackFile_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00985010` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-E) |
| **Counterpart** | `reviews/A_aa_00985010_AssPackManager_CompactPackFile_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Same as open-pack `FUN_00984ee0` | **Falsified** — compact orchestrator; **calls** open twice |
| 2 | ECX is AssPackManager* this | **Falsified** — ECX is **path**; hosts are **stack** objects; open uses EBX=host (W31-H) |
| 3 | `RET 4` stdcall | **Falsified** — bare `C3` after local frame teardown |
| 4 | Always silent | **Falsified** — `quiet==0` prints compacting progress + summary |
| 5 | In-memory only | **Falsified** — `MoveFileA`, `unlink`, `chmod`, temp `_pack_tmp.glm` |
| 6 | Has AssManager caller | **Falsified** — **0** static xrefs (unlike open-pack) |
| 7 | Product PDB name sealed | **Careful** — `_Inferred` from packer strings only |
| 8 | mode always identity passthrough | **Falsified** — `mode==3` replaces id with `(int16)node[+0x20]` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Compact stage order + I/O | **High** | Wrong tool port |
| Path ECX + quiet/mode | **High** | Wrong formals |
| Nested open ABI (EBX/ECX) | **High** (W31-H) | Mis-port open calls |
| Extract/write helpers | **Med** | Wrong per-file op |
| Invocation / shipping use | **Low/Open** | Dead code vs tool |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + strings

```
// entry: push ecx (path); mov esi, "glm"; call FUN_0076b190
// open1: push 1; lea ecx, path; lea ebx, packA; call FUN_00984ee0
// open2: push 0; mov ecx, "_pack_tmp.glm"; lea ebx, packB; call FUN_00984ee0
// strings: "Compacting file %s.\n"; "Packer compacted %d files.\n"; MoveFileA("_pack_tmp.glm", path)
// epi: add esp, 0x25c; ret
// xrefs: []
```

---

## 4. Surviving contract for AutoCore

```
// Port as offline packer compact (not gameplay path):
uint32_t CompactGlm(const char* path, int mode, bool quiet) {
  // rewrite path with .glm
  // AssResolverCore packA; OpenPack(packA, path, flag=1);
  // AssResolverCore packB; stage "_pk_"; OpenPack(packB, "_pack_tmp.glm", flag=0);
  // for each entry in packA: write into packB (mode==3 uses node short @+0x20);
  // close; unlink path; MoveFileA("_pack_tmp.glm", path); dtor hosts; return 0;
}
// Do not treat ECX as pack object. Do not assume AssManager calls this.
// Pair with AssPackManager_OpenPackFile_Inferred + AssResolverCore_Ctor_Inferred.
```

---

## 5. Verdict

Adversarial pass confirms A on compact semantics, formals, open dual, replace-via-temp. Nested helpers + zero-xref invocation residual → **accept-with-gaps**.
