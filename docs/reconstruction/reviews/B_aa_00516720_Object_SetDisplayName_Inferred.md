# Review B (skeptical / adversarial): `aa_00516720` Object_SetDisplayName_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00516720` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R10-031) |
| **Counterpart** | `reviews/A_aa_00516720_Object_SetDisplayName_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is a skill-cast / HB helper | **Falsified** — no skill opcodes, no HB insert, no combat pools; pure string field write; multi-object create/clone callers |
| 2 | Creature-only helper (`Named_CalleeOf_CVOGCreature_*` as full scope) | **Falsified** — also `Vehicle_applyCreatePacket`, `AllocateNewObjectFromCbid`, `Object_CreateFromEmbeddedCbid`, weapon/clone paths (16 xrefs) |
| 3 | `__cdecl` / bare `RET` | **Falsified** — both epilogues `RET 4` (`C2 04 00`); thiscall with one stack arg |
| 4 | Null name clears `+0x158` | **Falsified** — null check jumps to return **before** free of `+0x158` |
| 5 | Always stores input string | **Falsified** — fallback leaves `+0x158` NULL when name equals template default or `strlen ≤ 1` |
| 6 | Compose path always runs | **Falsified** — requires `vtbl+0x60 != 0` AND `+0xA4 != 0` AND `FUN_004ce940() != 0` |
| 7 | Field is `+0x56` bytes | **Falsified** — `param_1[0x56]` is dword index → byte offset `0x158` (`MOV [ESI+0x158]`) |
| 8 | Decompiler fallback `operator_new` size expression is bit-exact | **Attack stands as decompiler trap** — assembly uses **saved entry strlen** at `[ESP+0x0C]`; clean must follow assembly |
| 9 | Product symbol is known English without `_Inferred` | **Fails** — no PDB plate; role sealed only |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + `RET 4` + one `char*` formal | **Confirmed** | Stack imbalance / wrong this |
| `+0x158` owned display-name pointer | **Confirmed** | Wrong field wipe on create/clone |
| Null-name early-out preserves prior name | **Confirmed** | Accidental clear on optional name paths |
| Compose gates (vtbl+0x60 / +0xA4 / manager) | **Confirmed** | Missing affix composition |
| Compose via `FUN_005146a0` cap `0x5A` | **Confirmed** | Truncation / wrong buffer |
| Fallback differ + len>1 store rule | **Confirmed** | Spurious custom names / missing customs |
| Multi-caller shared object role | **Confirmed** | Under-scoped creature-only port |
| vtbl+0x60 product English | **High** (gate role) / **Low** (name) | Doc only |
| Product plate `Object_SetDisplayName_*` | **High** (role) / **Inferred** (symbol) | Rename churn |
| Runtime / bit-exact | **Open** | Unverified edge cases |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 decompile body preserved (append-only re-verify)
live decompile 2026-08-05 ≡ same CF
assembly + read_memory seal ABI / offsets / RET 4

00516720  81 EC 88 00 00 00              SUB  ESP, 0x88
00516727  8B AC 24 90 00 00 00           MOV  EBP, [ESP+0x90]  ; name*
00516732  3B EF                          CMP  EBP, EDI         ; null → far ret
00516734  8B F1                          MOV  ESI, ECX         ; this
0051673A  8B 86 58 01 00 00              MOV  EAX, [ESI+0x158]
0051674C  89 BE 58 01 00 00              MOV  [ESI+0x158], EDI
00516764  FF 50 60                       CALL [EAX+0x60]
0051676C  39 BE A4 00 00 00              CMP  [ESI+0xA4], EDI
0051677A  6A 5A                          PUSH 0x5A
... compose FUN_005146a0 ...
          C2 04 00                       RET  4   (compose path)
... fallback FUN_004eb240 / strncmp 0x41 / optional strdup ...
          C2 04 00                       RET  4   (fallback end)
body end exclusive 00516899
```

Reject ports that:

- Treat this as skill HB / cast helper or creature-only.
- Use cdecl / bare `RET` / stdcall `RET 8`.
- Clear `+0x158` on null name.
- Always `strdup` input without compose gates or default compare.
- Use byte offset `0x56` instead of `0x158`.
- Trust decompiler fallback alloc-size expression over saved strlen.
- Drop `_Inferred` without PDB evidence.
- Claim runtime Confirmed without Launcher evidence.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail object display-name assigner (shared create/clone/packet paths).
// thiscall; one stack string; RET 4.
// +0x158 = owned heap name or null (null ⇒ template default in UI).
// Null input is a no-op (does not clear).
// Compose when vtbl+0x60, host +0xA4, and name manager are live.
// Else store only if name differs from template default and length > 1.

void Object_SetDisplayName_Inferred(GameObject self, string? nameOrNull)
{
    if (nameOrNull is null) return;

    Free(self.DisplayNameAt158);
    self.DisplayNameAt158 = null;

    if (self.Vtbl60Count() != 0
        && self.HostAtA4 is not null
        && NameManager.Get() is not null)
    {
        var composed = ComposeDisplayName(self, nameOrNull, cap: 0x5A);
        self.DisplayNameAt158 = StrDup(composed);
        return;
    }

    var def = TemplateDefaultName(self.DescAtA8); // wide→MB path
    if (!StrNCmpEq(nameOrNull, def, 0x41) && nameOrNull.Length > 1)
        self.DisplayNameAt158 = StrDup(nameOrNull);
}
```

---

## 5. Verdict

**accept-with-gaps** — adversarial attacks on skill-only scope, creature-only scope, wrong convention, null-clear, always-store, and wrong field width are **falsified** by sealed bytes + callers. Remaining gaps are product English, vtbl+0x60 naming, manager type, CString typing detail, and runtime.
