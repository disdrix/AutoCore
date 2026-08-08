# Review B (skeptical / adversarial): `aa_00614c80` CVOGHBSkill_Master_Execute

| Field | Value |
|---|---|
| **Stable ID** | `aa_00614c80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R11-011) |
| **Counterpart** | `reviews/A_aa_00614c80_CVOGHBSkill_Master_Execute.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Void return / cdecl / `ret 0` | **Falsified** — `mov eax,1` + `ret 0x18` |
| 2 | Direct multi-caller graph | **Falsified** — sole xref is **DATA** vtbl slot `0x009d0e98`; `get_function_callers` empty |
| 3 | This is the Master **ctor** | **Falsified** — body is table walk + `new` children; factory uses `DefaultCtor`+vtbl stamp for type 3 |
| 4 | Object size `0x6d0` (SpawnEntities) | **Falsified** — `push 0x6c0` / catalog type 3 size `0x6c0` |
| 5 | Vtbl is `PTR_FUN_009d0ec4` (SpawnEntities) | **Falsified** — imm `009d0e6c`; RTTI **Master** not spawn |
| 6 | Still anonymous `FUN_005788d0` without base identity | **Falsified as identity** — `CVOGHBSkillBase_ctor` / dualed RTTI base |
| 7 | Resolve takes three free args with CONCAT type pointer | **Falsified shape** — `__thiscall` Resolve; `ECX=*(map+0xe4e8)`; type is entry `+8` byte |
| 8 | Can return 0 on failure | **Falsified** — both exits load `EAX=1` |
| 9 | Scaffold “unknown system” is product classification | **Falsified** — skills-abilities; Master element type 3 |
| 10 | Runtime Confirmed / bit-exact | **Not claimed** — no Launcher; open |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| CF loop / sentinel / fan-out | **High** | Wrong multi-target HB spawn |
| ABI `thiscall` + 6 args + ret 0x18 | **High** | Stack corruption in ports |
| RTTI class Master | **High** | Mis-bind element type |
| Method English “Execute” | Medium | Naming only; slot role still High |
| Child same-vtbl intent | Medium | Port may need distinct subclass |
| Formal C++ types | Low / open | Wrong map/table ownership |

---

## 3. Cross-check against raw + bytes

```
; epilogue
B8 01 00 00 00     mov eax, 1
… 
C2 18 00           ret 0x18

; child path
68 C0 06 00 00     push 0x6c0
E8 … → operator_new
E8 … → CVOGHBSkillBase_ctor @ 005788d0
C7 06 6C 0E 9D 00  mov [esi], PTR_FUN_009d0e6c
83 7E 18 00        cmp [esi+0x18], 0
; then Enqueue(map+0xe4ec) + Start  OR  call [vtbl](1)
```

Clean must **not** invent: terrain spawn, creature template strings, size `0x6d0`, SpawnEntities vtbl, void/cdecl, or direct call sites.

Decompiler `CONCAT31` on Resolve arg0 is **noise** — do not port as pointer synthesis.

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape (client skill HB element type 3 = Master)
// Virtual execute on CVOGHBSkill_Master (vtbl+0x2c):
//   foreach entry in targetTable[0..99] stride 16:
//     if sentinel(-1,-1,type0) return 1
//     obj = ResolveObjectTarget(map.resolveCtx, entry.type, entry.id0, entry.id1)
//     if obj == null continue
//     child = new MasterHb(0x6c0)  // base ctor + Master vtbl
//     if child.owner == null: delete child
//     else Enqueue(map.hbList) + Start(child)
//   return 1
// ABI: thiscall, 6 stack args, ret 0x18, always true/1
```

Do **not** treat as SpawnEntities execute (`0x00615020` / vtbl `009d0ec4` / size `0x6d0`).

---

## 5. Open questions

1. Product method symbol (PDB) for vtbl+0x2c.
2. Who builds the 100-cap target table argument.
3. Whether children should remain Master class in a server reimplementation.
4. Runtime capture of Master skill multi-target fan-out.

**Verdict:** **accept-with-gaps**
