# Dual A/B report — `aa_005134e0` Object_HasFlag8SelfOrLinked (mask **0x08** @ **+0x184**)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W17-E  
**Scope:** OWN ONLY VA `0x005134e0`. Dual A/B + artifacts. Seal flag mask **`0x08`**.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` only (no `disassemble_bytes`).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005134e0` Object_HasFlag8SelfOrLinked | **accept-with-gaps** — **mask `0x08` / bit 3 @ `+0x184` sealed** |

---

## Sealed facts

1. **Mask `0x08`** = **bit 3** of flags at **`obj+0x184`**.  
   Bytes: `b2 08` / `24 08` / `test […+0x184], dl`. Peers saying “bit 8” mean the **imm mask**, not bit index 8.

2. **Role:** link-aware **boolean exclude predicate** (not Broken, not dirty, not equip).  
   Callers reject/remove when true (`FUN_0058a810` + `filterB==0`, targeting HB, AI target pick, contact countdown).

3. **ABI:** ECX = object; **no** stack args; bool in AL; **`ret`** (`c3`).  
   Boundary: `0x005134e0` … `0x00513540`.

4. **Three paths:**
   - `+0xac == null` → `(obj+0x184 & 8) != 0`
   - parent non-null, `vtbl+0x19c()` non-null → self OR `(related + MI_adj + 0x188) & 8`
   - parent non-null, related null → self OR `(parent+0x184 & 8)`

5. **Live decompile ≡ 2026-07-23 raw** (append-only live section recorded).

6. **Not this unit:** Broken setter `0x00513de0`; dirty `0x00512670`; equip `0x004fabc0`.

---

## Gaps

1. Product English for flag mask `0x08` at `+0x184`.  
2. Product name of parent vtbl `+0x19c` (related/owner resolve).  
3. Full layout proof that MI `+0x188` is the same logical field as `+0x184`.  
4. Original PDB symbol.  
5. Runtime capture / bit-exact / image diff.

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005134e0_Object_HasFlag8SelfOrLinked.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005134e0_Object_HasFlag8SelfOrLinked.md` |
| Function record | `docs/reconstruction/functions/aa_005134e0_FUN_005134e0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_HasFlag8SelfOrLinked.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005134e0.cpp` |
| Raw (authoritative + live) | `docs/reconstruction/raw/aa_005134e0_FUN_005134e0.md` |
| Annotated | `docs/reconstruction/raw/aa_005134e0_FUN_005134e0.annotated.md` |
| This report | `docs/agents/task-dual-ab-005134e0-object-hasflag8selforlinked-report.md` |

Absolute roots: `C:\Users\josh\Documents\GitHub\AutoCore\` + paths above.

---

## AutoCore impact

- Client/server soft-exclude checks that need “object or linked parent flagged” should mirror the **OR** of self `+0x184&8` with linked related/parent — not self alone when `+0xac` is set.  
- Do **not** map this flag to **ItemFlag_Broken** (`+0x17c` bit 19) or dirty `0x20000`.
