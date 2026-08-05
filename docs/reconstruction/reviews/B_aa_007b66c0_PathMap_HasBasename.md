# Review B (skeptical / adversarial): `aa_007b66c0` PathMap_HasBasename

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b66c0` |
| **Review type** | Skeptical / adversarial (OWN-ONLY dual B / W17-M) |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007b66c0_PathMap_HasBasename.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | `__cdecl` / caller cleans stack | Epilogue `RET 4` | **Falsified** — stack arg cleaned by callee |
| 2 | Path is stack/thiscall ECX | Bytes `MOV EDI,EAX` then push EDI into strrchr | **Falsified** — **path in EAX** |
| 3 | Returns full 32-bit status codes | Only `AL=0/1` set | **Clarify** — bool in AL; upper EAX undefined |
| 4 | Flag test is any-nonzero on +4 | `TEST byte,2` / JBE | **Clarify** — only **bit 1 (mask 2)** |
| 5 | Takes first separator (dirname) | max pointer of `\` and `/` then +1 | **Falsified as dirname** — **basename** |
| 6 | Prefers `\` always over `/` | Only when `\` is later (`pcVar2 < pcVar1`) | **Clarify** — later-in-string wins |
| 7 | `FUN_00989e00` is free/delete | Decompile of callee = string intern into pool | **Falsified** |
| 8 | Virtual +0x14 is thiscall on ctx itself | Bytes load `ECX=[EBP+0xc]` then `[ECX]` vtbl | **Clarify** — call on **child object** at `ctx+0xc` |
| 9 | Dual decompiles disagree | force ≡ decompile | **No conflict** |
| 10 | Legacy name via CVOGCreature SetupGraphics | Callers are path/UI loaders | **Falsified** as product parent |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Flag gate mask 2 | **High** | Wrong enable for map |
| Basename rule | **High** | Path key mismatch in port |
| EAX path + RET 4 | **High** | ABI corruption |
| Pool `0x00d1eac8` | **High** | Wrong intern context |
| Map method product name | Medium | Mislabel in docs only |
| Whether hit means "exists as file" vs "registered token" | Medium | Over-interpreting return |

---

## 3. Cross-check: decompile vs bytes

| Step | Decompile | Bytes |
|---|---|---|
| Gate | `*(byte*)(param_1+4) & 2` | `F6 45 04 02` / JBE fail |
| strrchr | two calls | IAT via `0x009c662c`; push `5C`/`2F` |
| basename | max sep +1 | `CMP ESI,EAX` / `JBE` / `LEA EDI,[EAX+1]` |
| intern | `FUN_00989e00(&param_1, path)` | `MOV ECX,0x00d1eac8` + CALL |
| lookup | vtbl+0x14 | `MOV ECX,[EBP+0xC]; MOV EDX,[ECX]; CALL [EDX+0x14]` |
| return | 0 or 1 | `XOR AL,AL` / `MOV AL,1` + `RET 4` |

**Consensus:** accept.

---

## 4. Surviving contract for AutoCore

```csharp
// Behavior-exact sketch — not a drop-in without string pool + map types
static bool PathMap_HasBasename(PathMapContext ctx, string path)
{
    if ((ctx.FlagsByte & 2) == 0) return false;
    string baseName = Path.GetFileName(path.Replace('\\','/')); // last component
    if (string.IsNullOrEmpty(baseName)) baseName = path;
    var token = StringPool.Intern(baseName); // FUN_00989e00 @ pool 0x00d1eac8
    return ctx.Map.Lookup(token) != null;    // virtual +0x14
}
```

Do **not** treat as filesystem `PathFileExists` — that is a sibling path in `NDUIWindow_LoadInterfaceFile`.
