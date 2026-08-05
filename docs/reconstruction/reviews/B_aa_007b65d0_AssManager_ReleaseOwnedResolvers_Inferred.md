# Review B (skeptical / adversarial): `aa_007b65d0` AssManager_ReleaseOwnedResolvers_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b65d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W29-D) |
| **Counterpart** | `reviews/A_aa_007b65d0_AssManager_ReleaseOwnedResolvers_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus meta/xrefs; no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is a generic empty dtor / only nulls pointers | **Falsified** — list remove + scalar delete + log path |
| 2 | ECX thiscall (`mov ebx,ecx` in body) | **Falsified** — body never loads this from ECX; **EBX** is this |
| 3 | Both arms are identical | **Falsified** — arm A calls `FUN_00423e00` + string-vector prune; arm B find/erase/log |
| 4 | `DAT_00d1f1fc` loop walks 20 distinct vector shells | **Falsified** — EDI reloaded from global each iter; **same** shell, max 20 first-erases |
| 5 | Element stride is dword / 4 | **Falsified** — signed div path uses **`0x1c`** (string bag) |
| 6 | Log fires for arm A misses too | **Falsified** — log only on arm B find-fail (string push sites only on that path) |
| 7 | Erase helper is raw `memmove` only | **Falsified** — arm B uses sealed **`FUN_0043c550` EraseFirstEqual** |
| 8 | Scaffold `unaff_EBX` void plate is sufficient dual | **Falsified** — EBX ABI + dual arms + globals required |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EBX this + slots +8/+0xc | **High** | UAF / leak wrong fields |
| assManager string identity | **High** | wrong subsystem attribution |
| GuardedVector at +0x58 | **High** | erase wrong container |
| Arm A max-20 first erase | **High** | incomplete/wrong side-table clear |
| `FUN_00423e00` key=EAX | **Medium** | arm A remove wrong key if unowned helper differs |
| Product English | Medium | naming only |

---

## 3. Cross-check against raw + bytes

```
if [ebx+8]:
  ECX=*DAT_00d1f058; call FUN_00423e00
  scalar_delete([ebx+8],1); [ebx+8]=0
  ×0x14: erase-first 0x1c-elem on *DAT_00d1f1fc via FUN_0044d4e0
if [ebx+0xc]:
  key=[ebx+0xc]; ESI=*DAT_00d1f058+0x58
  if !FUN_0043e5b0(&key): log assManager.cpp:0x27b
  else FUN_0043c550(&key)
  scalar_delete([ebx+0xc],1); [ebx+0xc]=0
ret
```

Clean must **not** invent ECX this without EBX, treat both arms as the same helper, assume flat dword vector at `DAT_00d1f1fc`, or drop the log-on-miss path.

---

## 4. Surviving contract for AutoCore

```csharp
// Dtor body — this in EBX
void ReleaseOwnedResolvers(AssManagerResolverEntry self)
{
    if (self.ResolverA != null) {
        RemoveResolverFromManagerList(Manager, self.ResolverA); // FUN_00423e00
        ScalarDelete(self.ResolverA);
        self.ResolverA = null;
        for (int i = 0; i < 20; i++)
            EraseFirstStringElemIfAny(SideStringVec); // FUN_0044d4e0, stride 0x1c
    }
    if (self.ResolverB != null) {
        var key = self.ResolverB;
        var vec = Manager + 0x58; // GuardedVector
        if (!ContainsEqual(vec, key)) // FUN_0043e5b0
            Log(assManager.cpp, 0x27b, 3, "Removing resolver not found");
        else
            EraseFirstEqual(vec, key); // FUN_0043c550
        ScalarDelete(self.ResolverB);
        self.ResolverB = null;
    }
}
```

Do not port as a simple pair of `Release()` calls without the manager vector / string-vector side effects.

---

## 5. Open questions

1. Product type of resolver interface / entry class.  
2. Full dual of `FUN_00423e00` (does it require EAX=key?).  
3. Identity of `DAT_00d1f1fc` string table in assManager domain.  
4. Runtime concurrent remove under CS (container has lockEnable at +0x2c per find helper).

**Verdict:** **accept-with-gaps**
