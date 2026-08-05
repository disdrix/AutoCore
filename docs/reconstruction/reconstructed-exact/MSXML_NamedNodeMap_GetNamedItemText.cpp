// =============================================================================
// MSXML_NamedNodeMap_GetNamedItemText
// -----------------------------------------------------------------------------
// Stable ID: aa_00798bb0
// Address:   0x00798bb0–0x00798c9d  (autoassault.exe, image base 0x400000)
// System:    msxml / XML attribute helpers
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W17-G)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - ABI: __cdecl; 3 stack args; caller cleans; returns char in AL (1 ok / 0 fail).
 * - Ghidra 2-arg print is incomplete: callers pass (map, attrNameW, outWcharBuf).
 * - COM:
 *     map->vtbl[+0x1c] = IXMLDOMNamedNodeMap::getNamedItem(BSTR, IXMLDOMNode**)
 *     node->vtbl[+0x68] = IXMLDOMNode::get_text(BSTR*)
 *     node->vtbl[+0x08] = IUnknown::Release
 * - SysAllocString on attr name; OOM → FUN_004048e0(0x8007000e) noreturn.
 * - Success: wcscpy(out, textBstr); free text + name; return 1.
 * - Used by typed attribute parsers (int/float/range) that swscanf the buffer.
 */

#include <cstdint>
#include <oleauto.h>
#include <wchar.h>

// Minimal COM shapes (offsets only — not full IDL)
struct IUnknownVtbl {
  void *QueryInterface;  // +0x00
  void *AddRef;          // +0x04
  HRESULT(__stdcall *Release)(void *self);  // +0x08
};

struct IXMLDOMNamedNodeMapVtbl {
  IUnknownVtbl unk;
  void *IDispatch_pad[4];  // +0x0c .. +0x18
  HRESULT(__stdcall *getNamedItem)(void *self, BSTR name, void **outNode);  // +0x1c
};

struct IXMLDOMNodeVtbl {
  IUnknownVtbl unk;
  void *IDispatch_pad[4];
  void *node_methods_before_get_text[18];  // through clone/nodeTypeString
  HRESULT(__stdcall *get_text)(void *self, BSTR *out);  // +0x68 (slot 26)
};

struct IXMLDOMNamedNodeMap {
  IXMLDOMNamedNodeMapVtbl *lpVtbl;
};

struct IXMLDOMNode {
  IXMLDOMNodeVtbl *lpVtbl;
};

// External (owned elsewhere)
extern void FUN_004048e0(uint32_t hr);  // noreturn _com_raise_error-style

char __cdecl MSXML_NamedNodeMap_GetNamedItemText(
    IXMLDOMNamedNodeMap *map,
    const OLECHAR *attrName,
    wchar_t *outText)
{
  BSTR nameBstr;
  BSTR textBstr;
  IXMLDOMNode *attrNode;
  HRESULT hr;

  // SEH (LAB_009ac344) omitted

  if (attrName == nullptr) {
    nameBstr = nullptr;
  } else {
    nameBstr = SysAllocString(attrName);
    if (nameBstr == nullptr) {
      FUN_004048e0(0x8007000Eu);  // E_OUTOFMEMORY — does not return
    }
  }

  attrNode = nullptr;
  hr = map->lpVtbl->getNamedItem(map, nameBstr, reinterpret_cast<void **>(&attrNode));
  if (hr >= 0 && attrNode != nullptr) {
    textBstr = nullptr;
    hr = attrNode->lpVtbl->get_text(attrNode, &textBstr);
    attrNode->lpVtbl->unk.Release(attrNode);
    if (hr >= 0) {
      wcscpy(outText, textBstr);
      SysFreeString(textBstr);
      SysFreeString(nameBstr);
      return 1;
    }
    SysFreeString(textBstr);
  }

  SysFreeString(nameBstr);
  return 0;
}
