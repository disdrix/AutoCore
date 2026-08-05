# Review B (skeptical / adversarial): `aa_005d4fd0` Object_UnloadGraphics_Entry_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d4fd0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-AB) |
| **Counterpart** | `reviews/A_aa_005d4fd0_Object_UnloadGraphics_Entry_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This **is** the full UnloadGraphics body | **Falsified** — calls `FUN_005825d0` (W31-T) then chains |
| 2 | Free function / no this | **Falsified** — `MOV ESI,ECX`; MI negative offsets |
| 3 | Ends with bare RET like core | **Falsified** — `FF 60 04` tail JMP; decompiler “call+return” overstated |
| 4 | Has direct CODE callers | **Falsified** — 8 DATA xrefs only |
| 5 | Format always has valid `%d` | **Overstated** — only one intentional vararg after format; residual |
| 6 | Name is retail demangle | **Overstated** — inferred from string + core relationship |
| 7 | Deletes / frees object | **Falsified** — no `operator_delete`; chains to base method |
| 8 | Same as `FUN_00582670` sibling | **Falsified** — different size/CF; sibling takes stack param (W31-T context) |
| 9 | Runtime verified | **Open** — no Launcher |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Logged unload entry role | **High** | Wrong lifecycle order |
| Calls W31-T core | **High** | Miss untrack/FX teardown |
| Tail JMP this-0x40 | **High** | Broken MI chain |
| DATA-only install | **High** | Wrong call graph |
| `%d` second arg | **Low/Open** | Log noise only |
| Product vfunc names | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
ESI=this
nameId = *(nameRec+0x34) or -1
arg = root.vtbl+0x160(nameId)
log(-1, "UnloadGraphics on %s (%d)", arg)
FUN_005825d0(ESI)
JMP [*(ESI-0x40)+4] with ECX=ESI-0x40
```

Live 2026-08-04 ≡ raw 2026-07-23 CF spine; 85 B hex sealed. W31-T documented this VA as sole CODE caller of core — consistent (entry → core).

---

## 4. Surviving contract for AutoCore

```
// Vtable entry (not free function):
Object_UnloadGraphics_Entry_Inferred(mi_this);
// 1) log with name resolve (best-effort; %d residual)
// 2) Object_UnloadGraphics_Inferred(mi_this)  // W31-T sealed body
// 3) chain base method at this-0x40, vtbl+4 (tail)
// Do not free this here. Do not skip core. Prefer bytes for tail (not call+ret).
```

---

## 5. Verdict

Adversarial pass **confirms** A: log+core+tail role, DATA-only, tail JMP sealed; format-arg residual + product English open → **accept-with-gaps**.
