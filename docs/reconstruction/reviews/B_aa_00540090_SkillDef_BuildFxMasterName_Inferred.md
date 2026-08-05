# Review B (skeptical / adversarial): `aa_00540090` SkillDef_BuildFxMasterName_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00540090` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W24-N) |
| **Counterpart** | `reviews/A_aa_00540090_SkillDef_BuildFxMasterName_Inferred.md` |
| **Scratch** | `tmp/a_00540090.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | thiscall / ECX skill | **Falsified** — no `mov ecx` use; stack args + plain ret; caller `add esp,0xC` |
| 2 | Writes path with directory separators | **Falsified** — pure underscore tags; no `\` or `/` |
| 3 | Class tag uses `"b_"` for case 2 | **Falsified** — case 2 uses `"c_"` (`DAT_009cf9ec`); `"b_"` lives adjacent unused here |
| 4 | Appends extension `.xml` | **Falsified** — basename only; LoadMaster adds path/ext |
| 5 | Operates on full RB node base | **Risk** — call sites pass **node+0x10**; offsets are relative to that payload base |
| 6 | Name field at +0x5B6 absolute on node | **Agree if** payload=node+0x10 → +0x5a6 maps to +0x5B6 |
| 7 | Multiple independent string builders | **Falsified as distinct CF** — single function; three callers share it |
| 8 | Scaffold invents CF | **Attack fails** — live ≡ raw 2026-07-23 body |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Format skill_ + tags + name | **High** | Wrong FX master XML key |
| cdecl 3-arg ABI | **High** | Stack imbalance if treated thiscall |
| Payload = node+0x10 convention | **High** (call sites) | Offset mis-align if called on node base |
| Enum product labels | **Open** | Docs only |
| Runtime matrix | **Open** | Policy |

---

## 3. Cross-check against raw + bytes

```
sub esp, 0x400
buf = "skill_"
append class(+0x180): 0→h_ 1→m_ 2→c_ else→n_
append cat(+0x17c): 0→c_ 1→e_ 2→o_ 3→r_ else→fixme_
append C-string(+0x5a6)
strncpy(out, buf, cap)
ret          // cdecl
```

Caller EnsureMasterAndResolve:
```
// when hash value master flag@+0x0a == 0 and SkillDefMap hit:
FUN_00540090(node+0x10, stackBuf, 0x400)
FUN_004a6390(stackBuf)  // FxMaster_LoadMasterFromXML
```

Live decompile ≡ raw CF; string table sealed via `read_memory`.

---

## 4. Surviving contract for AutoCore

```
// Skill FX master basename (client)
BuildFxMasterName(skillPayload, out, cap):
  out = "skill_" + classTag(skillPayload.field_180)
                + categoryTag(skillPayload.field_17c)
                + skillPayload.name_5a6

// classTag:  0→"h_" 1→"m_" 2→"c_" else→"n_"
// category:  0→"c_" 1→"e_" 2→"o_" 3→"r_" else→"fixme_"

// Do NOT:
//  - treat as thiscall
//  - pass full RB node without +0x10
//  - expect ".xml" / directory path from this function
//  - invent "b_" as class-2 tag (unused here)
```

---

## 5. CF challenge of Review A

No material CF dispute. Naming remains **Inferred** (no PDB). Enum English open but tags closed.

**Verdict:** **accept**
