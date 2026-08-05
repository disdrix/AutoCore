# Review B (skeptical / adversarial): `aa_0054a1a0` SkillAuxMap_ClearAndReset

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054a1a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0054a1a0_SkillAuxMap_ClearAndReset_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Same map as skill-def tree (`DAT_00b04734/38`, nil `+0x641`) | Body uses `DAT_00b04744` and nil `+0x15` | **Falsified** — **distinct** aux map |
| 2 | Cast-time helper on each RequestCast | Only caller is EnsureInitialized bootstrap | **Falsified** — load/init only |
| 3 | Decompiler “operator_delete does not return” means abort | CRT delete returns; map walk continues after | **Noise** — ignore noreturn label |
| 4 | Clears skill-def install map used by ExactFind | ExactFind uses `DAT_00b04734` + `00418c70` | **Falsified** — different globals |
| 5 | Name implies complete product semantics | Payload type / key type unknown | **Open** — structural name only |
| 6 | No side effects beyond locals | Mutates process globals head/count | **Confirmed side effects** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Global targets `B04744` / `B04748` | **High** | Wrong map cleared on skill reload |
| Nil `+0x15` family | **High** | Porting wrong node stride |
| Only EnsureInitialized caller | **High** | Invented cast-path dependency |
| Payload-only free semantics | **Medium** | Leak if nodes also need free beyond decompile |
| Product map identity | **Low** | Naming only |

---

## 3. Surviving contract for AutoCore

```csharp
// Bootstrap only — not per-cast
void SkillAuxMap_ClearAndReset()
{
    // walk map at g_skillAuxMapHead (DAT_00b04744)
    // nil flag at node+0x15; free payload at node+0x10 (dword[4])
    // reset head self-links; g_skillAuxMapCount (DAT_00b04748) = 0
}
```

**Port traps:**

- Reusing skill-def node layout (`+0x641` nil, key `+0x0C`).
- Calling from RequestCast / LocalCastValidate.
- Skipping payload free at `node[4]`.

---

## 4. Residual gaps

1. What keys/values live in this aux map.
2. Relationship of `FUN_0054d7c0` full node free vs payload free in the walk.
3. Runtime seal.

**Verdict:** **accept-with-gaps** — CF + globals sealed; product map identity open.
