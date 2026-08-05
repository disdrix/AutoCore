# Review B (skeptical / adversarial): `aa_0054a290` SkillDef_InstallLoadedRecord

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054a290` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0054a290_SkillDef_InstallLoadedRecord_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Per-cast validation helper | Callers are EnsureInitialized + `00517400` load paths | **Falsified** — install/bootstrap |
| 2 | Empty-element log aborts process | `FUN_007a4480` then **return** | **Falsified** — soft fail for that skill only |
| 3 | Single map update only | Two-phase: staging map (`0054d9a0`/`0054e9a0`) **and** ExactFind/runtime map (`00418890`/`0054ea60`) | **Clarify** — dual map family |
| 4 | Always inserts | Hit path **overwrites** `node+0x10` / copy-template | **Falsified** if claimed insert-only |
| 5 | `0x24b` is byte offset | Index is dword index in decompile (`param_1 + 0x24b` as `undefined4*`) → byte **`0x92C`** | **Port trap** — use byte offset carefully |
| 6 | Server authority | Client table install only | **Confirmed client** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Empty elements → log + skip | **High** | Broken skills silently half-installed |
| Dual map update skeleton | **High** | Missing runtime template on ports |
| Flag packing from class byte | **High CF / Low product** | Wrong skill behavior flags |
| String materialize + free | **High** | Leaks / UAF on ports |
| Nested FUN product names | **Low** | Doc only |

---

## 3. Surviving contract for AutoCore

```csharp
void SkillDef_InstallLoadedRecord(SkillDefBlob* blob)
{
    if (blob->ElementCountShort == 0) {
        Log("Skill %d had no skill elements - it won't work.", blob->SkillId);
        return; // do NOT throw
    }
    // pack flags from ClassByte (1..5) + optional bits
    // upsert staging map row (0x14e dwords at node+0x10)
    // Skill_InitializeRuntimeObject(...)
    // ExactFind skill id → copy 0x18c dwords template OR insert
}
```

**Port traps:**

- Treating empty-elements as hard process stop.
- Skipping ExactFind / `Skill_CopyRuntimeFieldsFromTemplate` arm.
- Confusing dword index `0x24b` with byte offset `0x24b`.
- Calling from cast path instead of table load.

---

## 4. Residual gaps

1. Nested install helpers dual units.
2. Flag/class product enums.
3. Runtime seal.

**Verdict:** **accept-with-gaps** — install CF + empty-gate sealed; field product names open.
