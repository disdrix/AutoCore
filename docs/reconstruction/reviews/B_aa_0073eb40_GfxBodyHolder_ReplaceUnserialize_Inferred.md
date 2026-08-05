# Review B (skeptical / adversarial): `aa_0073eb40` GfxBodyHolder_ReplaceUnserialize_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073eb40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W38-R) |
| **Counterpart** | `reviews/A_aa_0073eb40_GfxBodyHolder_ReplaceUnserialize_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler `void` return | **Falsified as complete** — both arms leave EAX = unserializer status; no clobber before RET |
| 2 | cdecl / no stack cleanup | **Falsified** — `C2 04 00` RET 4; thiscall + 1 stack arg |
| 3 | `FUN_0076a900` needs no reader | **Falsified** — ESI loaded from stack formal; PeekChunkTag unaff_ESI |
| 4 | SAMB path only takes body | **Falsified** — `PUSH ESI` then `PUSH body`; `ADD ESP,8` after call |
| 5 | Always GBOD | **Falsified** — explicit `CMP EAX,'SAMB'` + JNZ |
| 6 | Known inbound callers | **Open** — Ghidra xrefs empty; do not invent |
| 7 | Product name `gfxBodyMassageMachine::Load` | **Rejected** — keep `_Inferred` structural name |
| 8 | Dead after replace if new fails | **Nuanced** — null body still peeks/dispatches (bytes do not early-out) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + RET 4 | **High** | ABI crash |
| SAMB/GBOD dispatch | **High** | wrong format path |
| EAX status passthrough | **High** | silent status loss |
| inbound callers | **Open** | reachability |
| product English | **Low** | naming only |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against raw + bytes + callees

```
// Sole static caller of GfxBody_UnserializeGBOD (W37-S):
//   FUN_0073eb40 @ 0073ebce  PUSH body; CALL 00765740

// SAMB master:
//   FUN_009615c0 plates: gfxBodyMassageMachine.cpp / "Invalid TAG unserializing gfxBodyMaster"

// Peek:
//   FUN_0076a900 ESI=reader (W19-R dualed)
```

Closes W37-S residual “caller is 0073eb40 — dual open”.

---

## 4. Surviving contract for AutoCore

```
// Port as thiscall holder replace+load:
uint32_t GfxBodyHolder_ReplaceUnserialize(Holder* h, stoChunkReader* r) {
  if (h->body) scalar_delete(h->body, 1);
  h->body = new_or_null_GfxBody_0x14C();
  if (PeekTag(r) == 'SAMB') return UnserializeMaster(h->body, r);
  return UnserializeGBOD(h->body, r); // stdcall peer
}
// Do NOT drop EAX status. Do NOT assume inbound callers known.
```

---

## 5. Verdict

**accept-with-gaps** — ABI/CF/tags sealed; callers + product English open.
